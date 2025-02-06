/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:15 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 12:18:16 by baguiar-         ###   ########.fr       */
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
    firstName = firstName;
    lastName = lastName;
    nickName = nickName;
    phoneNumber = phoneNumber;
    darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}