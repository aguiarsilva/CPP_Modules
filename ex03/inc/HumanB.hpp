#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(const std::string name);
        ~HumanB(void);
        void attack() const;
        void setWeapon(Weapon& weapon);

    private:
        std::string name;
        Weapon* weapon;
};

#endif