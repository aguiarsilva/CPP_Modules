/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:44:12 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/12 22:44:12 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
    private:
        std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif