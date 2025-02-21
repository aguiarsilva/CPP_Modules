/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:58:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:58:42 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl test;

    std::cout << "Debug Level" << std::endl;
    test.complain("DEBUG");

    std::cout << std::endl;

    std::cout << "Info Level" << std::endl;
    test.complain("INFO");

    std::cout << std::endl;

    std::cout << "Warning Level" << std::endl;
    test.complain("WARNING");

    std::cout << std::endl;

    std::cout << "Error Level" << std::endl;
    test.complain("ERROR");

    std::cout << std::endl;

    std::cout << "Unknown Level" << std::endl;
    test.complain("BLOB");

    return 0;
}