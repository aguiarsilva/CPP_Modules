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
    heapZombie->announce();

    std::cout << std::endl;

    std::cout << "Stack Zombie using randomChump function" << std::endl;
    randomChump("Stack2");

    std::cout << std::endl;

    std::cout << "Heap Zombie using newZombie function" << std::endl;
    Zombie* heapZombie2 = new Zombie("Heap2");
    heapZombie2->announce();
    
    std::cout << std::endl;

    delete (heapZombie);
    heapZombie = NULL;
    delete (heapZombie2);
    heapZombie2 = NULL;

    return 0;
}