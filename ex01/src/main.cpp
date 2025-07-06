/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:23:57 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/06 13:48:46 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>
#include <string>

//Printing functions to test
void print_int(const int& x) { std::cout << x << " "; }
void print_double(const double& x) { std::cout << x << " "; }
void print_string(const std::string& x) { std::cout << x << " "; }

// Modifying functions to test
void increment(int& x) { x += 1; }
void to_upper(std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - ('a' - 'A');
    }
}

//main function


int main() 
{
    std::cout << "---- Array of Integers ----" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Original Array: " << std::endl;
    iter(arr, 5, print_int);
    std::cout << std::endl;

    iter(arr, 5, increment);

    std::cout << "----Incremented Array ----" << std::endl;
    iter(arr, 5, print_int);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "---- Array of Double ----" << std::endl;
    double darr[] = {1.1, 2.2, 3.3};

    std::cout << "Original Array: " << std::endl;
    iter(darr, 3, print_double);
    std::cout << std::endl;
    
    std::cout << std::endl;

    std::cout << "---- Array of Strings ----" << std::endl;
    std::string sarr[] = {"ich", "habe", "hunger!"};

    std::cout << "Original Array: " << std::endl;
    iter(sarr, 3, print_string);
    std::cout << std::endl;

    iter(sarr, 3, to_upper);

    std::cout << "Array after Upper: " << std::endl;
    iter(sarr, 3, print_string);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "---- Array of const integers ----" << std::endl;
    const int constArr[] = {10, 20, 30};

    iter(constArr, 3, print_int);
    std::cout << std::endl;

    return 0;
}
