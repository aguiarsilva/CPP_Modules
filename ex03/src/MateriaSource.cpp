/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:46:38 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/03 12:46:38 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_templates[i] = NULL;

    for (int i = 0; i < 4; i++)
        if (obj.m_templates[i] != NULL)
            m_templates[i] = obj.m_templates[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (m_templates[i])
            {
                delete m_templates[i];
                m_templates[i] = NULL;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (other.m_templates[i] != NULL)
                m_templates[i] = other.m_templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (m_templates[i])
            delete m_templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (m_templates[i] == NULL)
        {
            m_templates[i] = m;
            std::cout << "Materia learned succesfully" << std::endl;
            return; 
        }
    }
    std::cout << "No more available slots for new Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (m_templates[i] && m_templates[i]->getType() == type)
            return m_templates[i]->clone();
    }
    return NULL;
}