/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:13:09 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/17 15:30:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()

int main()
{

    std::cout << "== BASIC INITIAL TEST ==" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;

    std::cout << "== Exception Handling Tests ==" << std::endl;

    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch (const Span::MaxCapacity& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    try
    {
        Span sp(5);
        sp.addNumber(1);
        sp.shortestSpan();
    }
    catch (const Span::InsufficientElementsException& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "==Template Function Test==" << std::endl;
    
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    Span ssp(10);
    ssp.addNumbers(nums.begin(), nums.end());

    std::cout << "Shortest span: " << ssp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << ssp.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "==Large Scale test (10,000+ numbers)==" << std::endl;

    const int SIZE = 15000;
    Span bigSpan(SIZE);

    std::vector<int> largeNumbers;
    largeNumbers.reserve(SIZE);

    std::srand(std::time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        largeNumbers.push_back(std::rand() % 100000);
    }

    std::cout << "Adding " << SIZE << " numbers using template function..." << std::endl;
    bigSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());

    std::cout << "Calculating spans..." << std::endl;
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    std::cout << "Large scale test completed successfully!" << std::endl;

    return 0;
}
