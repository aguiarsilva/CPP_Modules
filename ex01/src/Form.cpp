/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:30:48 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/16 13:26:17 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : m_name("default"), m_signed(false), m_grade_s(150), m_grade_e(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : m_name(name), m_signed(false), m_grade_s(gradeToSign), m_grade_e(gradeToExecute)
{
	std::cout << "Form parametrized constructor called" << std::endl;

	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : m_name(obj.m_name), m_signed(obj.m_signed), m_grade_s(obj.m_grade_s), m_grade_e(obj.m_grade_e)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

//Getters
const std::string& Form::getName() const
{
	return m_name;
}

bool Form::isSigned() const
{
	return m_signed;
}

int Form::getGradeSign() const
{
	return m_grade_s;
}

int Form::getGradeExec() const
{
	return m_grade_e;
}

//member functions
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_grade_s)
		throw Form::GradeTooLowException();
	m_signed = true;
}

//Exceptions functions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Exception: Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Exception: Form grade too low";
}

//Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", Sign Status: " 
	   << (form.isSigned() ? "Signed" : "Not signed") 
	   << ", Grade to Sign: " << form.getGradeSign()
	   << ", Grade to Execute: " << form.getGradeExec();
	return os;
}
