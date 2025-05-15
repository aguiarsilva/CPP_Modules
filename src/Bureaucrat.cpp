/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:05:52 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/15 11:44:25 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//Orthodox Canonical Form
Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name)
{
	std::cout << "Constructor with parameters called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : m_name(obj.m_name), m_grade(obj.m_grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
	{
		m_grade = other.m_grade;
	}
	return *this;
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

//Getters
int Bureaucrat::getGrade() const
{
	return m_grade;
}

const std::string& Bureaucrat::getName() const
{
	return m_name;
}

//Grade management
void Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

//Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low!";
}

//Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "Bureaucrat: " << bureaucrat.getName() << " , grade: " << bureaucrat.getGrade();
	return os;
}
