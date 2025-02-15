#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA(void)
{
    std::cout << "HumanA destroyed" << std::endl;
    return ;
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}