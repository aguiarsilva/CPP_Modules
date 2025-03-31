/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:05 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/31 09:23:43 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	m_type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*(obj._brain));
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
    {
		Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*(other._brain));
    }
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain*   Dog::getBrain() const
{
    return _brain;
}
