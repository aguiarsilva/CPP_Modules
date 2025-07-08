/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:30:30 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:30:30 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Stack Zombie" << std::endl;
    Zombie stackZombie("Stack1");
    stackZombie.announce();

    std::cout << std::endl;

    std::cout << "Heap Zombie" << std::endl;
    Zombie* heapZombie = new Zombie("Heap1");
    heapZombie->announce();

    std::cout << std::endl;

    std::cout << "Stack Zombie using randomChump function" << std::endl;
    randomChump("Stack2");

    std::cout << std::endl;

    std::cout << "Heap Zombie using newZombie function" << std::endl;
    Zombie* heapZombie2 = new Zombie("Heap2");
    heapZombie2->announce();
    
    std::cout << std::endl;

    delete (heapZombie);
    heapZombie = NULL;
    delete (heapZombie2);
    heapZombie2 = NULL;

    return 0;
}