/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:12:07 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/17 15:12:09 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.hpp"
#include <iostream>

    FragTrap::FragTrap() : ClapTrap()
    {
        this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        std::cout << CYAN << "FragTrap constructor called" << RESET << std::endl;
    }

    FragTrap::FragTrap(std::string name) : ClapTrap(name)
    {
        this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        std::cout << CYAN << "FragTrap constructor with parameter called" << RESET << std::endl;
    }

    FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
    {
        std::cout << CYAN << "FragTrap copy constructor called" << RESET << std::endl;
    }

    FragTrap::~FragTrap()
    {
        std::cout << CYAN << "FragTrap " << name << " destroyed" << RESET << std::endl;
    }

    FragTrap& FragTrap::operator=(const FragTrap& other)
    {
        std::cout << CYAN << "FragTrap assignement operator called" << RESET << std::endl;
        if(this != &other)
            ClapTrap::operator=(other);
        return *this;
    }

    void    FragTrap::highFivesGuys(void)
    {
        std::cout << CYAN << "FragTrap " << this->name << " is feeling indestructible and wants a strong powerful high five! Anyone?"  << RESET << std::endl;
    }
