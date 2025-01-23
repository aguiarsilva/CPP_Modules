/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:46 by baguiar-          #+#    #+#             */
/*   Updated: 2025/01/23 10:58:04 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "colors.hpp"

class Contact{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
        std::string _input(std::string str);
        std::string _trim(std::string str);

    public:
        Contact(void);
        ~Contact(void);
        void    add(void);
        bool    valid(void);
        int     short_view(int index);
        void    large_view(void);
};

#endif
