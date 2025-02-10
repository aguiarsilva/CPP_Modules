/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:12:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/10 12:26:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Contacts.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

bool    isDigit(std::string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

std::string getInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    return input;
}

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    while (true)
    {
        std::cout << ("Enter command (ADD, SEARCH, EXIT): ");
        std::getline(std::cin, command);

        if (command == "EXIT" || command == "exit")
            break;
        else if (command == "ADD" || command == "add")
        {
            try
            {
                {
                    Contact newContact;
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickName);

            do 
            {
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                if (!isDigit(phoneNumber))
                    std::cout << "Error: Phone number must contain only numbers. Please try again." << std::endl;
            } while (!isDigit(phoneNumber));
            
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);

            if (firstName.empty() || lastName.empty() || nickName.empty() ||
                phoneNumber.empty() || darkestSecret.empty())
                {
                    std::cout << "Error: All fields must be completed!" << std::endl;
                    continue;
                }
                newContact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
                phonebook.addContact(newContact);
                }
            }
            catch(const std::exception& e)
            {
                std::cout << "Error adding contact: " << e.what() << std::endl;
            }
        }
        else if (command == "SEARCH" || command == "search")
        {
            phonebook.searchContact();
        }
        else
            std::cout << "Invalid command. Please use ADD, SEARCH or EXIT" << std::endl;
    }
    return 0;
}