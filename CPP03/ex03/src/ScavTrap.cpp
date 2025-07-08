/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:15:04 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/17 15:15:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << YELLOW << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << YELLOW << "ScavTrap constructor with parameter name called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << YELLOW << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << YELLOW << "ScavTrap assignment operator called" << RESET << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
     if (this->energyPoints <= 0)
        std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!" << std::endl;
    else if (this->hitPoints <= 0)
        std::cout << "ScavTrap " << name << " doesn't have enough hit points to attack!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target
                << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << MAGENTA << "ScavTrap " << getName() << " has entered Gate keeper mode!" << RESET << std::endl;
}
