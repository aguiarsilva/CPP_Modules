/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:15:45 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:15:45 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// #include <stdexcept>
// int main(void)
// {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
    
//     std::cout << "a: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a after pre-increment: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a after post-increment: " << a << std::endl;
    
//     std::cout << "b: " << b << std::endl;
    
//     std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

//     // Test: min
//     std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;

//     // Test: Comparison operators
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     // Test: Arithmetic operators
//     std::cout << "a + b: " << a + b << std::endl;
//     std::cout << "a - b: " << a - b << std::endl;
//     std::cout << "a * b: " << a * b << std::endl;
    
//     // Test: Division
//     std::cout << "a / b: " << a / b << std::endl;
    
//     // Edge case: Division by zero
//     Fixed zero(0);
//     try {
//         std::cout << "a / zero: " << a / zero << std::endl;  // Potential division by zero
//     } catch (const std::exception& e) {
//         std::cout << "Exception caught: " << e.what() << std::endl;  // Catch division by zero
//     }

//     // Edge case: Smallest possible value (near zero)
//     Fixed small1(0.0001f);
//     std::cout << "small1: " << small1 << std::endl;
//     std::cout << "small1 + b: " << small1 + b << std::endl;

//     // Edge case: Large value
//     Fixed large(1000000);
//     std::cout << "large: " << large << std::endl;
//     std::cout << "large + b: " << large + b << std::endl;

//     return 0;
// }
