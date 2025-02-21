/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:50:07 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:50:07 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(const std::string name);
        ~HumanB(void);
        void attack() const;
        void setWeapon(Weapon& weapon);

    private:
        std::string name;
        Weapon* weapon;
};

#endif