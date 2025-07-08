/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:45:45 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:45:45 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void announce(void) const;
        void setName(std::string name);
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif