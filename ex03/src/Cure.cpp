/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:00:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/01 09:00:08 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    //std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj.getType())
{
    //std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
    //std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
   // std::cout << "Cure assingment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
