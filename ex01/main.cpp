/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:12:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/01/23 12:40:31 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Contacts.hpp"
#include "Phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "Enter a command (ADD, SEARCH, EXIT):" << std::endl;
    std::getline(std::cin, command);

    while (command != "EXIT")
    {
        
    }
    
}