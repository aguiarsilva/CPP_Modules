/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:14:19 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/31 10:13:47 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		~Cat();
		Cat& operator=(const Cat& other);
		virtual void	makeSound() const;
        Brain*  getBrain() const;
	private:
        Brain* _brain;
	
};

#endif
