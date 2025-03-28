/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:14 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/28 09:15:17 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

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
    std::cout << std::endl;

    //Testing WrongAnimal
    std::cout << "Testing WrongAnimal" << std::endl;
    
    const WrongAnimal* wrongGeneric = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongGeneric->makeSound();
    std::cout << std::endl;

    return 0;
}
