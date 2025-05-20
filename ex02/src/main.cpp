/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:06:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/20 15:55:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	//Test 1
	try 
	{
		//Create the Bureaucrats for the tests
		std::cout << "Creating the Bureaucrats for the Execution tests" << std::endl;
		Bureaucrat littleGuy("Little Guy", 140);
		Bureaucrat bigGuy("Big Guy", 40);
		Bureaucrat theBoss("The Boss", 1);

		//Create forms with different requirements to test
		std::cout << "\nCreating Forms for tests" << std::endl;
		ShrubberyCreationForm firstLevel("Garden");
		RobotomyRequestForm secondLevel("Target");
		PresidentialPardonForm thirdLevel("Criminal");

		std::cout << "\n-- Form Information --" << std::endl;
		std::cout << firstLevel << std::endl;
		std::cout << secondLevel << std::endl;
		std::cout << thirdLevel << std::endl;
		std::cout << std::endl;

		//Test the signing process
		std::cout << "\n-- Signing Forms --" << std::endl;
		//Bureaucrat Little Guy should be able to sign first level form
		littleGuy.signForm(firstLevel);

		//Bureaucrat Little Guy should not be able to sign second level form
		littleGuy.signForm(secondLevel);

		//Bureaucrat Big Guy should be able to sign second level form
		bigGuy.signForm(secondLevel);

		//Bureaucrat Big Guy should not be able to sign third level form
		bigGuy.signForm(thirdLevel);

		//Bureaucrat The Boss should be able to sign third level form
		theBoss.signForm(thirdLevel);
		std::cout << std::endl;

		//Test execution of Forms
		std::cout << "\n-- Testing Execution of Forms --" << std::endl;
		littleGuy.executeForm(firstLevel);
		littleGuy.executeForm(secondLevel);
		bigGuy.executeForm(secondLevel);
		bigGuy.executeForm(thirdLevel);
		theBoss.executeForm(thirdLevel);
		std::cout << std::endl;

		//Test unsigned forms
		std::cout << "\n-- Testing unsigned form -- " << std::endl;

		ShrubberyCreationForm unsignedForm("UnsignedGarden");
		littleGuy.executeForm(unsignedForm);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
