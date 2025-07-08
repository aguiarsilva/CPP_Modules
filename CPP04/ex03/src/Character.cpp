/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:00:04 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/01 09:00:04 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

AMateria* Character::m_floor[1000] = {NULL};
int Character::m_floorCount = 0;

Character::Character() : m_name("")
{
    //std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;
}

Character::Character(std::string const& name) : m_name(name)
{
    //std::cout << "Character parameter constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;
}

Character::Character(const Character& obj) : m_name(obj.m_name)
{
    //std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;

    for (int i = 0; i < 4; i++)
    {
        if (obj.m_inventory[i] != NULL)
            m_inventory[i] = obj.m_inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other)
{
    //std::cout << "Character assingment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (m_inventory[i])
            {
                delete m_inventory[i];
                m_inventory[i] = NULL;
            }   
        }
        m_name = other.m_name;
        for (int i = 0; i < 4; i++)
        {
            if (other.m_inventory[i] != NULL)
                m_inventory[i] = other.m_inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    //std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (m_inventory[i])
            delete m_inventory[i];
    }
}

std::string const& Character::getName() const
{
    return m_name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (m_inventory[i] == NULL)
        {
            m_inventory[i] = m;
            return ;
        }
    }
    std::cout << "No more available slots for new Materia" << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx] != NULL)
    {
        if (m_floorCount < 1000)
        {
            m_floor[m_floorCount++] = m_inventory[idx];
        }
        m_inventory[idx] = NULL;
    }
}

void Character::cleanFloor()
{
    for (int i = 0; i < m_floorCount; i++)
    {
        delete m_floor[i];
        m_floor[i] = NULL;
    }
    m_floorCount = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx] != NULL)
        m_inventory[idx]->use(target);
}