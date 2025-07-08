/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:50:11 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/22 22:53:08 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		//Orthodox Canonical Form
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& other);
		~Intern();

		//member function
		AForm* makeForm(std::string form, std::string target);

		//Exception class for unknown form names
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		//need functions to create specific forms
		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyForm(const std::string& target);
		AForm* createPardonForm(const std::string& target);
};

#endif
