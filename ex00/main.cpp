#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Stack Zombie" << std::endl;
    Zombie stackZombie("Stack1");
    stackZombie.announce();

    std::cout << std::endl;

    std::cout << "Heap Zombie" << std::endl;
    Zombie* heapZombie = new Zombie("Heap1");
    heapZombie.announce();

    std::cout << "Stack Zombie using randomChump function" << std::endl;
    randomChump("Stack2");

    std::cout << "Heap Zombie using newZombie function" << std::endl;
    Zombie* heapZombie2 = newZombie("Heap2");
    newZombie.announce();

    delete (heapZombie);
    delete (heapZombie2);

    return 0;
}