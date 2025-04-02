/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:00:00 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/01 09:00:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

		AMateria::AMateria() : m_type("")
        {
            std::cout << "AMateria default constructor called" << std::endl;
        }

		AMateria::AMateria(std::string const &type) : m_type(type)
        {
            std::cout << "AMateria parameter constructor called" << std::endl;
        }

		AMateria::AMateria(const AMateria& other) : m_type(other.m_type)
        {
            std::cout << "AMateria copy constructor called" << std::endl;
        }

		AMateria& AMateria::operator=(const AMateria& other)
        {
            std::cout << "AMateria assingment operator called" << std::endl;
            if (this != &other)
                this->m_type = other.m_type;
            return *this;
        }

		AMateria::~AMateria()
        {
            std::cout << "AMateria destructor called" << std::endl;
        }
		
		std::string const& AMateria::getType() const
        {
                return this->m_type;
        }
		
		void AMateria::use(ICharacter& target)
        {
            (void)target;
        }