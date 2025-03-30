/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:14 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/30 23:22:07 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

int main()
{

    const Animal* dog1 = new Dog();
    const Animal* cat1 = new Cat();

    std::cout << dog1->getType() << " " << std::endl;
    std::cout << cat1->getType() << " " << std::endl;
    cat1->makeSound();
    dog1->makeSound();

    delete dog1;
    delete cat1;

    std::cout << std::endl;

    


    std::cout << std::endl;

    return 0;
}
