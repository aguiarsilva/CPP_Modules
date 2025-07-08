/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:40:37 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/08 08:50:45 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>
#include <exception>
#include <string>

int main()
{
    try
    {
        std::cout << "---- Array creation test ----" << std::endl;

        //int array
        Array<int> intArray(5);
        std::cout << "Created int array of size: " << intArray.size() << std::endl;

        // double array
        Array<double> doubleArray(3);
        std::cout << "Created double array of size: " << doubleArray.size() << std::endl;

        // string array
        Array<std::string> strArray(4);
        std::cout << "Created string array of size: " << strArray.size() << std::endl;        
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---- Element access tests ----" << std::endl;

    //default initialization
    Array<int> intArray(5);
    std::cout << "Default values in int array: " << std::endl;
    for (size_t i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << std::endl;

    //modification test
    std::cout << "Modifying elements: " << std::endl;
    for (size_t i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
        std::cout << "Set Array[" << i << "] = " << intArray[i] << std::endl;
    }

    //testing with strings
    Array<std::string> strArray(3);
    std::cout << "Default string values: " << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
    {
        std::cout << "strArray[" << i << "] = '" << strArray[i] << "'" << std::endl;
    }

    //modifying strArray
    strArray[0] = "Ich";
    strArray[1] = "habe";
    strArray[2] = "Hunger";

    std::cout << "String Array after modification: " << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
    {
        std::cout << "strArray[" << i << "] = '" << strArray[i] << "'" << std::endl;
    }

    return 0;
}

