/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:28 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:15:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignement operator called" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
