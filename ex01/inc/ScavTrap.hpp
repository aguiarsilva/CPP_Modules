/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:02:38 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/17 15:02:41 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    private:

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& obj);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& other);
        void guardGate();
        void attack(const std::string& target);
};

#endif
