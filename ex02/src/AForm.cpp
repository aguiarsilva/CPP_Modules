/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:30:48 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/20 15:58:24 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : m_name("default"), m_signed(false), m_grade_s(150), m_grade_e(150)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : m_name(name), m_signed(false), m_grade_s(gradeToSign), m_grade_e(gradeToExecute)
{
	std::cout << "AForm parametrized constructor called" << std::endl;

	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : m_name(obj.m_name), m_signed(obj.m_signed), m_grade_s(obj.m_grade_s), m_grade_e(obj.m_grade_e)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

//Getters
const std::string& AForm::getName() const
{
	return m_name;
}

bool AForm::isSigned() const
{
	return m_signed;
}

int AForm::getGradeSign() const
{
	return m_grade_s;
}

int AForm::getGradeExec() const
{
	return m_grade_e;
}

//member functions
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_grade_s)
		throw AForm::GradeTooLowException();
	m_signed = true;
}

//Exceptions functions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Exception: AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Exception: AForm grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Exception: AForm is not signed";
}

//Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", Sign Status: " 
	   << (form.isSigned() ? "Signed" : "Not signed") 
	   << ", Grade to Sign: " << form.getGradeSign()
	   << ", Grade to Execute: " << form.getGradeExec();
	return os;
}
