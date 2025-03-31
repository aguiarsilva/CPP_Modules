/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:18:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/31 11:48:37 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "../inc/ICharachter.hpp"

class AMateria
{
	protected:
		std::string m_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		
		std::string const& getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
};

#endif
