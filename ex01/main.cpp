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