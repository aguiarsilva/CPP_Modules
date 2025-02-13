#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void announce(void) const;
        void setName(std::string name);
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif