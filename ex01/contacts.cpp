/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:15 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 23:15:38 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

void Contact::setContact(std::string firstName, std::string lastName, std::string nickName,
            std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickName() const
{
    return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}