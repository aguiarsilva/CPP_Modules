#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        std::cout << "Number of Zombies must be greater than 0" << std::endl;
        return NULL;
    }

    Zombie* zHorde = new Zombie[N];
    if (zHorde == NULL)
    {
        std::cout << "Error: zHorde Not Allocated" << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; i++)
        zHorde[i].setName(name);
    return zHorde;
}