#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    const Animal* generic = new Animal();
    const Animal* dog1 = new Dog();
    const Animal* cat1 = new Cat();

    std::cout << dog1->getType() << " " << std::endl;
    std::cout << cat1->getType() << " " << std::endl;
    cat1->makeSound();
    dog1->makeSound();
    generic->makeSound();

    return 0;
}