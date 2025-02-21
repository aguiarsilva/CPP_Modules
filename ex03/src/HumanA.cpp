/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:14 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:56:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA(void)
{
    std::cout << "HumanA destroyed" << std::endl;
    return ;
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}