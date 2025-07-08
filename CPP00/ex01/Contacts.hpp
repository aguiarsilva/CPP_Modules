/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:46 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 11:48:25 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "colors.hpp"

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void setContact(std::string firstName, std::string lastName, std::string nickName,
            std::string phoneNumber, std::string darkestSecret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif
