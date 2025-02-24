#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("defaultName"), hitPoints(10), energyPoints(10), attackDamage(0)
{

}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{

}

ClapTrap::~ClapTrap()
{
    std::cout << "Player " << name << " destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!" << std::endl;
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough hit points to attack!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target
                << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints -= 1;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    
}

void    ClapTrap::beRepaired(unsigned int amount)
{

}