/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:53:31 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/03 14:53:06 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    return 0;
}

// int main()
// {
//     std::cout << "=== TEST 1: Basic Functionality ===" << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);  // Should cast Ice
//     me->use(1, *bob);  // Should cast Cure

//     std::cout << "\n=== TEST 2: Creating a non-existent Materia ===" << std::endl;
//     tmp = src->createMateria("fire");  // Should return NULL
//     if (!tmp)
//         std::cout << "Failed to create unknown materia (expected behavior)\n";
    
//     std::cout << "\n=== TEST 3: Learning more than 4 Materias ===" << std::endl;
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice()); // This should not be learned (exceeding limit)
    
//     std::cout << "\n=== TEST 4: Equipping more than 4 Materias ===" << std::endl;
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("cure"));
//     me->equip(src->createMateria("ice")); // Should be ignored

//     std::cout << "\n=== TEST 5: Using out-of-bounds Materia ===" << std::endl;
//     me->use(4, *bob); // Should do nothing

//     std::cout << "\n=== TEST 6: Unequipping Materia ===" << std::endl;
//     me->use(0, *bob);  // Use Ice
//     me->unequip(0);     // Unequip Ice
//     me->use(0, *bob);  // Should do nothing (slot empty)
    
//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }