/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:21 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/22 22:50:47 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

    //Orthodox Canonical Form
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

    //need functions to create specific forms
AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

    //member function
AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPardonForm
	};

	for(int i = 0; i < 3; i++)
	{
		if (form == formNames[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw Intern::UnknownFormException();
}

    //Exception class for unknown form names
const char* Intern::UnknownFormException::what() const throw()
{
	return "Exception: Unknown form name";
}
