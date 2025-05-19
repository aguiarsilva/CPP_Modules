/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:06:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/16 13:55:34 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	//Test 1
	try 
	{
		//Create the Bureaucrat
		std::cout << "Creating the Bureaucrat for the Form tests" << std::endl;
		Bureaucrat pepe("Pepe", 50);
		std::cout << pepe << std::endl;

		//Create forms with different requirements to test
		std::cout << "\nCreating Forms for tests" << std::endl;
		Form firstLevel("Simple Authorization", 130, 130);
		Form secondLevel("Standard Contract", 50, 30);
		Form thirdLevel("Top Secret Document", 10, 5);

		std::cout << "\n-- Form Information --" << std::endl;
		std::cout << firstLevel << std::endl;
		std::cout << secondLevel << std::endl;
		std::cout << thirdLevel << std::endl;

		//Test the signing process
		std::cout << "\n-- Signing Forms --" << std::endl;
		//Bureaucrat should be able to sign first level form
		pepe.signForm(firstLevel);
		std::cout << firstLevel << std::endl;

		//Bureaucrat should be able to sign second level form
		pepe.signForm(secondLevel);
		std::cout << secondLevel << std::endl;

		//Bureaucrat should not be able to sign third level form
		pepe.signForm(thirdLevel);
		std::cout << thirdLevel << std::endl;

		//Test high/low grades in form creation
		std::cout << "\n-- Testing Invalid Form Grades --" << std::endl;
		Form invalidForm("Invalid", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Test 2
	try
	{
		Form invalidForm("Invalid", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
