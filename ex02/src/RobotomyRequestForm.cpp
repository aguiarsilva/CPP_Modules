/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:59:53 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/20 15:59:54 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

//Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
	std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), m_target(obj.m_target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//member function
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();

	//make drilling noises
	std::cout << "* DRILLING NOISES * Bzzzz... Whirrrr... Clank! Clank! Pow! Pow!" << std::endl;

	//generates random number of seeds
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	if (std::rand() % 2)
	{
		std::cout << m_target << " has been robotomized succesfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << m_target << " failed!" << std::endl;
	}

}
