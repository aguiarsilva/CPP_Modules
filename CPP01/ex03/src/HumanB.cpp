/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:20 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:56:20 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name) : name(name), weapon(NULL)
{

}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destroyed" << std::endl;
    return;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}