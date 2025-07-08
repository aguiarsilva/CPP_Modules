/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:40:37 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/08 09:19:49 by baguiar-         ###   ########.fr       */
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
    
        std::cout << std::endl;

    //testing with strings
    Array<std::string> strArray(3);
    std::cout << "Default string values: " << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
    {
        std::cout << "strArray[" << i << "] = '" << strArray[i] << "'" << std::endl;
    }

        std::cout << std::endl;

    //modifying strArray
    strArray[0] = "Ich";
    strArray[1] = "habe";
    strArray[2] = "Hunger";

    std::cout << "String Array after modification: " << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
    {
        std::cout << "strArray[" << i << "] = '" << strArray[i] << "'" << std::endl;
    }
    
    std::cout << std::endl;

    //Testing copy constructor
    std::cout << "---- Testing copy constructor ----" << std::endl;
    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Array<int> copy(original);
    std::cout << "Original: ";
    for (size_t i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << "\nCopy: ";
    for (size_t i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    // Deep copy testing
    copy[0] = 999;
    std::cout << "After modifying copy[0] = 999:" << std::endl;
    std::cout << "Original[0]: " << original[0] << " (should still be 10)" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;

    std::cout << std::endl;

    //Testing assignment operator
    std::cout << "---- Testing Assignment operator ----" << std::endl;
    Array<int> arr1(3);
    Array<int> arr2(5);
    arr1[0] = 100;
    arr1[1] = 200;
    arr1[2] = 300;

    arr2 = arr1;
    std::cout << "After assignment, arr2 size: " << arr2.size() << std::endl;
    
    std::cout << std::endl;

    // Test deep copy again
    arr2[0] = 777;
    std::cout << "Original arr1[0]: " << arr1[0] << " (should be 100)" << std::endl;
    std::cout << "Assigned arr2[0]: " << arr2[0] << " (should be 777)" << std::endl;
    
    std::cout << std::endl;

    //Testing exceptions
    std::cout << "---- Exception tests ----" << std::endl;
    Array<int> testArray(3);
    try {
        std::cout << "Accessing valid index [2]: " << testArray[2] << std::endl;
        std::cout << "Trying to access invalid index [5]..." << std::endl;
        std::cout << testArray[5] << std::endl;  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access negative index [-1]..." << std::endl;
        std::cout << testArray[-1] << std::endl;  // Should throw (if size_t handles this)
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    //Testing with empty array
    std::cout << "---- Empty array test ----" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    try {
        std::cout << emptyArray[0] << std::endl;  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Accessing empty array threw: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    //Test with different types
    std::cout << "---- Different types test ----" << std::endl;
    Array<char> charArray(3);
    charArray[0] = 'A';
    charArray[1] = 'B';
    charArray[2] = 'C';
    for (size_t i = 0; i < charArray.size(); i++)
        std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;

    return 0;
}

