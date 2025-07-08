/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:14:27 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/17 15:14:30 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("defaultName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << YELLOW << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << YELLOW << "ClapTrap Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{   
    *this = obj;
    std::cout << YELLOW << "ClapTrap Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << YELLOW << "ClapTrap Copy assignment operator called" << RESET << RESET << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!" << std::endl;
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough hit points to attack!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target
                << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return ;
    }
    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << name << " has been defeated!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << name << " took " << amount << " points damage. The HP now is " << this->hitPoints << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int amountToHeal;

    if (amount < (10 - this->hitPoints))
        amountToHeal = amount;
    else
        amountToHeal = 10 - this->hitPoints;

    if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough energy points to be repaired!" << std::endl;
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have any hit points left!" << std::endl;
    else
    {
        this->energyPoints--;
        this->hitPoints += amountToHeal;
        std::cout << "ClapTrap " << name << " recovered " << amountToHeal << " hit points!" << std::endl;
    }
}

std::string ClapTrap::getName() const
{
    return name;
}

int    ClapTrap::getHitPoints() const
{
    return hitPoints;
}

int     ClapTrap::getEnergyPoints() const
{
    return energyPoints;
}

int     ClapTrap::getAttackDamage() const
{
    return attackDamage;
}
