/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:05 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:15:07 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	m_type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
