#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	m_type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if (this != &other)
		this->m_type = other.m_type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
