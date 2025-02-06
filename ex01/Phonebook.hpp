/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:32 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/06 12:25:08 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook 
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void addContact(const Contact& contact);
        void searchContact() const;
        void displayContact(int index) const;
        std::string truncateString(std::string str) const;
        
    private:
        Contact contacts[8];
        int     index;
        int     totalContacts;

        
};

#endif