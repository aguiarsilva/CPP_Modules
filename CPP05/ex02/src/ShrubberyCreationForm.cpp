/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:56 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/19 14:54:35 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

//Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), m_target(obj.m_target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//member functions
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	//Check if form is signed
	if (!this->isSigned())
		throw AForm::NotSignedException();
	//Check executors grade
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	//Create file and write to it
	std::string filename = m_target + "_shrubbery";
	std::ofstream output(filename.c_str());

	//check if file was created
	if (!output)
	{
		std::cerr << "Error creating the file: " << filename << std::endl;
		return;
	}

	//Write ASCII trees to file
	output << "    /\\    " << std::endl;
    output << "   /$$\\   " << std::endl;
    output << "  /$$$$\\  " << std::endl;
    output << " /$$$$$$\\ " << std::endl;
    output << "/$$$$$$$$\\" << std::endl;
	output << "    ||     " << std::endl;
    output << "    ||     " << std::endl;
    output << "    ||     " << std::endl;
    output << std::endl;
    output << "    /\\    " << std::endl;
    output << "   /**\\   " << std::endl;
    output << "  /****\\  " << std::endl;
    output << " /******\\ " << std::endl;
    output << "/********\\" << std::endl;
	output << "    ||     " << std::endl;
    output << "    ||     " << std::endl;
    output << "    ||     " << std::endl;

    output.close();
    std::cout << "Shrubbery has been created in " << filename << std::endl;
}