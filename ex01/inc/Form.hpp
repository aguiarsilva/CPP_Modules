/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:20 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/16 12:49:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_signed;
		const int m_grade_s;
		const int m_grade_e;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& obj);
		Form& operator=(const Form& other);
		~Form();

	//Getters
	const std::string& getName() const;
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;

	//member functions
	void beSigned(const Bureaucrat& bureaucrat); 

	//Exception classes
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
