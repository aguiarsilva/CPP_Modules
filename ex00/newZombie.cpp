
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* zumbizera = new Zombie(name);
    zumbizera->announce();
    return zumbizera;
}
