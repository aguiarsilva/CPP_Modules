/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:48:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:48:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string introBrain = "HI THIS IS BRAIN";

    std::string* stringPTR = &introBrain;
    std::string& stringREF = introBrain;

    std::cout << "\nAddresses: " << std::endl;
    std::cout << "Memory address of variable: " << &introBrain << std::endl;
    std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "\nValues: " << std::endl;
    std::cout << "Value of introBrain: " << introBrain << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return 0;
}