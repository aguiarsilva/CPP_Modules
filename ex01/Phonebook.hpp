/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:32 by baguiar-          #+#    #+#             */
/*   Updated: 2025/01/23 10:53:13 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
        bool    _full;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        
};

#endif