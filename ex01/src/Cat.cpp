/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:14:59 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/30 23:20:01 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Animal.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
    m_type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*(obj._brain));
}

Cat::~Cat()
{
    delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if (this != &other)
    { 
		Animal::operator=(other);
		delete _brain;
        this->_brain = new Brain(*(other._brain));
    }
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
