#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type)
{
    this->setType(type);
}

Weapon::~Weapon()
{
    std::cout  << this->getType() << " destroyed" << std::endl;
    return;
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}