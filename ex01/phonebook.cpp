/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/01/23 12:33:09 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
    this->_index = 0;
    this->_full = false;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << RED << "PhoneBook destroyed" << DEFAULT << std::endl;
    return ;
}

