#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name) : name(name), weapon(NULL)
{

}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destroyed" << std::endl;
    return;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}