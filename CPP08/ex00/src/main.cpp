/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:28:43 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/14 11:13:43 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename Iterator>
void printResult(Iterator result, Iterator end)
{
    if (result != end)
        std::cout << "Found: " << *result << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}

int main() 
{
    std::cout << "== VECTOR TESTS ==" << std::endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    //Test 1 - Element exists in vector
    std::vector<int>::iterator result = easyfind(vec, 3);
    printResult(result, vec.end());

    std::cout << std::endl;

    //Test 2 - Element doesn't exists in vector
    result = easyfind(vec, 99);
    printResult(result, vec.end());
    
    std::cout << std::endl;

    //Test 3 - First element
    result = easyfind(vec, 1);
    printResult(result, vec.end());

    std::cout << std::endl;

    //Test 4 - Last element
    result = easyfind(vec, 5);
    printResult(result, vec.end());

    std::cout << std::endl;

    //Test 5 - Empty Vector
    std::vector<int> empty_vec;
    std::vector<int>::iterator empty_result = easyfind(empty_vec, 1);
    printResult(empty_result, empty_vec.end());

    std::cout << std::endl;

    std::cout << "== LIST TESTS == " << std::endl;

    std::list<int> myList;
    myList.push_back(1);
    myList.push_back(20);
    myList.push_back(300);
    myList.push_back(4000);
    myList.push_back(50000);

    //Test 1 - Element exists in list
    std::list<int>::iterator list_result = easyfind(myList, 300);
    printResult(list_result, myList.end());

    std::cout << std::endl;

    //Test 2 - Element doesn't exists in list
    list_result = easyfind(myList, 2);
    printResult(list_result, myList.end());

    std::cout << std::endl;

    //Test 3 - First Element
    list_result = easyfind(myList, 1);
    printResult(list_result, myList.end());

    std::cout << std::endl;

    //Test 4 - Last Element
    list_result = easyfind(myList, 50000);
    printResult(list_result, myList.end());

    std::cout << std::endl;

    //Test 5 - Empty List
    std::list<int> empty_list;
    std::list<int>::iterator list_empty = easyfind(empty_list, 2);
    printResult(list_empty, empty_list.end());

    std::cout << std::endl;

    std::cout << "== DEQUE TESTS ==" << std::endl;
    std::deque<int> myDeque;
    myDeque.push_back(100);
    myDeque.push_back(200);
    myDeque.push_back(300);
    myDeque.push_back(400);
    myDeque.push_back(500);

    //Test 1 - Element exists in deque
    std::deque<int>::iterator deque_result = easyfind(myDeque, 300);
    printResult(deque_result, myDeque.end());

    std::cout << std::endl;

    //Test 2 - Element doesn't exists in deque
    deque_result = easyfind(myDeque, 1);
    printResult(deque_result, myDeque.end());

    std::cout << std::endl;

    //Test 3 - First Element
    deque_result = easyfind(myDeque, 100);
    printResult(deque_result, myDeque.end());

    std::cout << std::endl;

    //Test 4 - Last Element
    deque_result = easyfind(myDeque, 500);
    printResult(deque_result, myDeque.end());

    std::cout << std::endl;

    //Test 5 - Empty deque
    std::deque<int> empty_deque;
    std::deque<int>::iterator deque_empty = easyfind(empty_deque, 3);
    printResult(deque_empty, empty_deque.end());

    std::cout << std::endl;

    return 0;
}
