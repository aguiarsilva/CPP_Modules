/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:06:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/27 11:47:58 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	try 
	{
		std::cout << "Creating the Bureaucrat and Intern for tests" << std::endl;
		Intern intern;
		Bureaucrat boss("The Boss", 1);
		
		// Create forms with immediate cleanup on exception
		AForm* shrubForm = NULL;
		AForm* robotForm = NULL; 
		AForm* pardonForm = NULL;
		
		try {
			shrubForm = intern.makeForm("shrubbery creation", "garden");
			robotForm = intern.makeForm("robotomy request", "target");
			pardonForm = intern.makeForm("presidential pardon", "criminal");
			
			// Your existing code for printing, signing, executing...
			std::cout << "\n-- Form Information --" << std::endl;
			std::cout << *shrubForm << std::endl;
			std::cout << *robotForm << std::endl; 
			std::cout << *pardonForm << std::endl;
			std::cout << std::endl;
			
			std::cout << "\n-- Signing and executing the Forms --" << std::endl;
			boss.signForm(*shrubForm);
			boss.executeForm(*shrubForm);
			std::cout << std::endl;
			boss.signForm(*robotForm);
			boss.executeForm(*robotForm);
			std::cout << std::endl;
			boss.signForm(*pardonForm);
			boss.executeForm(*pardonForm);
			std::cout << std::endl;
			
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
			delete shrubForm;
			delete robotForm;
			delete pardonForm;
			throw;
		}
		delete shrubForm;
		delete robotForm;
		delete pardonForm;
		
		// Test invalid form
		try {
			std::cout << " \n-- Testing invalid form --" << std::endl;
			AForm* invalidForm = intern.makeForm("unknown form", "target");
			(void)invalidForm; // This won't execute
		} catch (std::exception& e) {
			std::cout << "Exception for invalid form: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}