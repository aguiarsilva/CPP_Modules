#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& obj);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& other);
        void    whoAmI();

    private:
        std::string name;
};

#endif