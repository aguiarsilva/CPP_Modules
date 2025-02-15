
#include "Zombie.hpp"
#include <iostream>

//constructor
Zombie::Zombie(void)
{
    std::cout << "Initializing Zombie" << std::endl;
    return ;
}

//destructor
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

//public methods
void Zombie::announce(void) const
{
    std::cout << name << ":" << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
