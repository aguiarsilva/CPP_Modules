/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:14:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:14:13 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string m_type;

    public:
        Animal();
        Animal(const Animal& obj);
        ~Animal();
        Animal& operator=(const Animal& other);
        virtual void    makeSound() const;
        std::string     getType() const;
};

#endif
