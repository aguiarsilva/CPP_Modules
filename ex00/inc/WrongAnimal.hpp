/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:14:33 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:14:35 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string m_type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& obj);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& other);
        void    makeSound() const;
        std::string     getType() const;
};

#endif

