/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 12:38:42 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const
{
    
}

void PhoneBook::displayContact(int index) const
{
    std::cout << "Contact information:" << std::endl;
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
