/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:14:50 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:14:53 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    m_type = "Animal";
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = obj;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignement operator called" << std::endl;
    if (this != &other)
        this->m_type = other.m_type;
    return *this;
}

std::string     Animal::getType() const 
{
    return m_type;
}

void    Animal::makeSound() const
{
    std::cout << "Generic animal sound" << std::endl;
}
