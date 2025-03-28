/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:21 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:15:23 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    m_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = obj;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    if (this != &other)
        this->m_type = other.m_type;
    return *this;
}

std::string     WrongAnimal::getType() const 
{
    return m_type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Generic animal sound" << std::endl;
}
