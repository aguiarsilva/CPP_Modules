/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:41:28 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:41:28 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//constructor
Zombie::Zombie(void)
{
    std::cout << "Initializing Zombie" << std::endl;
    return ;
}

//destructor
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

//public methods
void Zombie::announce(void) const
{
    std::cout << name << ":" << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
