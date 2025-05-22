/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:06:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/22 22:44:08 by baguiar-         ###   ########.fr       */
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
	//Test 1
	try 
	{
		//Create the Bureaucrat and Intern for the tests
		std::cout << "Creating the Bureaucrat and Intern for tests" << std::endl;
		Intern intern;
		Bureaucrat boss("The Boss", 1);

		//Test valid form creation
		std::cout << "\nTesting valid form creation" << std::endl;
		AForm* shrubForm = intern.makeForm("shrubbery creation", "garden");
		AForm* robotForm = intern.makeForm("robotomy request", "target");
		AForm* pardonForm = intern.makeForm("presidential pardon", "criminal");

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

		std::cout << "--- Testing invalid form name ---" << std::endl;
		AForm* invalidForm = intern.makeForm("unknown form", "target");
		(void)invalidForm;

		delete shrubForm;
		delete robotForm;
		delete pardonForm;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
