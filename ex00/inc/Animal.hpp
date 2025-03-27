#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string m_type;

    public:
        Animal();
        Animal(const Animal& obj);
        ~Animal();
        Animal& operator=(const Animal& other);
        virtual void    makeSound() const;
        std::string     getType() const;
};

#endif
