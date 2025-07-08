/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:04:52 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/16 13:28:06 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string m_name;
		int               m_grade;

	public:
		//Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		//Getters
		int getGrade() const;
		const std::string& getName() const;

		//Grade management
		void incrementGrade();
		void decrementGrade();

		//Signature function
		void signForm(Form& form);

		//Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

//Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
