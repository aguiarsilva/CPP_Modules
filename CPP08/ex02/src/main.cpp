/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:45:49 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/20 13:25:34 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "== Basic Stack operations test ==" << std::endl;

    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    if (ms.top() == 3 && ms.size() == 3)
    {
        std::cout << "Passed" << std::endl;
    } 
    else
    {
        std::cout << "Failed" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "== Forward iteration test (1, 2, 3) ==" << std::endl;

    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "== Reverse iteration test (3, 2, 1) ==" << std::endl;
    for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    
    std::cout << "== Test empty Stack ==" << std::endl;
    MutantStack<int> empty;
    std::cout << "Emtpy Stack size: " << empty.size() << std::endl;

    std::cout << std::endl;

    return 0;
}
