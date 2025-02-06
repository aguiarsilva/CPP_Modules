/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 14:28:22 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <stdexcept>

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    this->totalContacts = 0;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << RED << "PhoneBook destroyed" << DEFAULT << std::endl;
    return ;
}

void PhoneBook::addContact(const Contact& contact)
{
    contacts[index] = contact;

    std::cout << GREEN << "\nContact was added successfully at index " << index << std::endl;
    if (totalContacts == 8)
        std::cout << YELLOW << "Warning: last contact was replaced (phonebook is full)" << std::endl;
    
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const
{
    //First check if phonebook is not empty.
    if (totalContacts == 0)
    { 
        std::cout << "Phonebook is empty!" << std::endl;
        return ;
    }
       
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << std::setfill("-") << std::setw(44) << "-" << std::endl;
    std::cout << std::setfill(" ");

    for (int i = 0; i <= totalContacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname()) << "|" << std::endl;
    }
    
    std::string input;
    std::cout << "/nEnter the index to display contact: ";
    std::getline(std::cin >> input);

    try 
    {
        int index = std::stoi(input);
        if (index < 0 || index >= totalContacts)
            throw std::out_of_range("Invalid index number!");
        displayContact(index);
    }
    catch (const std::invalid_arguments& e)
    {
        std::cerr << "Error: Invalid input. Please enter a number." << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: Index out of range!" << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    std::cout << "\nContact information:" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    
}

std::string PhoneBook::truncateString(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}
