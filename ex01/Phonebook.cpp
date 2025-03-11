/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/11 15:04:17 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <stdexcept>
#include <sstream>

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    this->totalContacts = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << RED << "PhoneBook destroyed" << DEFAULT << std::endl;
}

void PhoneBook::addContact(const Contact& contact)
{
   try
   {
    if (totalContacts < 8)
    {
        contacts[index] = contact;
        std::cout << GREEN << "\nContact was added successfully at index " << index << DEFAULT <<std::endl;
        totalContacts++;
    }
    else
    {
        contacts[index] = contact;
        std::cout << GREEN << "\nContact was added successfully at index 7" << DEFAULT << std::endl;
        std::cout << YELLOW << "Warning: last contact was replaced (phonebook is full)" << DEFAULT << std::endl;
    }
    index = (index + 1) % 8;
   }
   catch (const std::exception& e)
   {
        std::cout << "Error adding contact: " << e.what() << std::endl;
   }
}

void PhoneBook::searchContact() const
{
    //First check if phonebook is not empty.
    if (totalContacts == 0)
    { 
        std::cout << "Phonebook is empty!" << std::endl;
        return ;
    }
    try
    {
         std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
        std::cout << std::setfill('-') << std::setw(44) << "-" << std::endl;
        std::cout << std::setfill(' ');

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickName()) << "|" << std::endl;
    }
    
    std::cout << "\nEnter the index to display contact: ";
    std::string input;
    std::getline(std::cin, input);

        std::istringstream iss(input);
        int index;
        if (!(iss >> index))
            throw std::runtime_error("Invalid index number!");
        if (index < 0 || index >= totalContacts)
            throw std::out_of_range("Index is out of range!");
        displayContact(index);
    
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
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
    try
    {
        {
            if (str.empty())
                return str;
            if (str.length() > 10)
                return str.substr(0,9) + ".";
            return str;
        }
    }
    catch(const std::exception& e)
    {
        return "";
    }
}
