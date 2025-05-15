/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:06:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/05/15 12:05:58 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	//Test 1
	try 
	{
		//Test a valid bureaucrat
		std::cout << "Test: Bureaucrat with valid grade" << std::endl;
		Bureaucrat pepe("Pepe", 3);
		std::cout << pepe << std::endl;

		//Test the increment function
		std::cout << "\nIncrementing grade" << std::endl;
		pepe.incrementGrade();
		std::cout << pepe << std::endl;

		//Test the decrement function		
		std::cout << "\nDecrementing grade" << std::endl;
		pepe.decrementGrade();
		std::cout << pepe << std::endl;

		//Test Grade too high
		std::cout << "\nTest: Bureaucrat with too high grade" << std::endl;
		Bureaucrat marge("Marge", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Test 2
	try
	{
		//Test Grade too low
		std::cout << "\nTest: Bureaucrat with too low grade" << std::endl;
		Bureaucrat charlie("Charlie", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Test 3
	try
	{
		//Test increment beyond max
		std::cout << "\nTest: incrementing bureaucrat grade over the max (1)" std::endl;
		Bureaucrat caesar("Caesar", 1);
		std::cout << caesar << std::endl;
		caesar.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Test 4	
	try
	{
		//Test decrement beyond max
		std::cout << "\nTest: decrementing bureaucrat grade over the min (150)" std::endl;
		Bureaucrat nero("Nero", 150);
		std::cout << nero << std::endl;
		caesar.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
