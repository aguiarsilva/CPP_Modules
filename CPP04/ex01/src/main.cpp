/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:14 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/31 09:14:44 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

int main()
{
    std::cout << "Testing old classes" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    std::cout << std::endl;

    std::cout << "Testing Brain class" << std::endl;
    //create and fill array of Animal objects
    const int arr_size = 6;
    const Animal* animals[arr_size];

    for (int i = 0; i < arr_size/2; i++)
        animals[i] = new Dog();
    for (int i = arr_size/2; i < arr_size; i++)
        animals[i] = new Cat();

    for (int i = 0; i < arr_size; i++)
        animals[i]->makeSound();
    
    for (int i = 0; i < arr_size; i++)
        delete animals[i];
    
    std::cout << "Testing deep copy" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Sniff around");

    Dog copiedDog(originalDog);
    copiedDog.getBrain()->setIdea(0, "Chase cat");

    std::cout << "Original dog " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    return 0;
}
