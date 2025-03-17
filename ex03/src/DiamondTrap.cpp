#include "DiamondTrap.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap(), name("Diamond")
{
    std::cout << BG_MAGENTA << "DiamondTrap constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    std::cout << BG_MAGENTA << "DiamondTrap constructor with parameter called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name(obj.name)
{
    std::cout << BG_MAGENTA << "DiamondTrap copy constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << BG_MAGENTA << "DiamondTrap " << name << " destroyed" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << BG_MAGENTA << "DiamondTrap assignement operator called" << RESET << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

void   DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name " << this->name << " and ClapTrap name: " << ClapTrap::name << std::endl;
}