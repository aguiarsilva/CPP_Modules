#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("defaultName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
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
        this->energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return ;
    }
    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << name << " has been defeated!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << name << " took " << amount << " points damage. The HP now is " << this->hitPoints << std::endl;
    }
}


void    ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int amountToHeal;

    if (amount < (10 - this->hitPoints))
        amountToHeal = amount;
    else
        amountToHeal = 10 - this->hitPoints;

    if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have enough energy points to be repaired!" << std::endl;
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " doesn't have any hit points left!" << std::endl;
    else
    {
        this->energyPoints--;
        this->hitPoints += amountToHeal;
        std::cout << "ClapTrap " << name << " recovered " << amountToHeal << " hit points!" << std::endl;
    }
}