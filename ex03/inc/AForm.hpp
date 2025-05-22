/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:20 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/19 13:20:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string m_name;
		bool m_signed;
		const int m_grade_s;
		const int m_grade_e;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

	//Getters
	const std::string& getName() const;
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;

	//member functions
	void beSigned(const Bureaucrat& bureaucrat); 

	//Execute function
	virtual void execute(Bureaucrat const& executor) const = 0;

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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
