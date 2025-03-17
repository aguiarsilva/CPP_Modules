#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
    private:

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& obj);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& other);
        void guardGate();
        void attack(const std::string& target);
};

#endif