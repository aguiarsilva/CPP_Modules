/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:41:55 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:41:55 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
    int numZombies = 5;
    std::string zName = "Pete";

    Zombie* horde = zombieHorde(numZombies, zName);

    for (int i = 0; i < numZombies; i++)
        horde[i].announce();

    delete[] horde;
    horde = NULL;

    return 0;
}