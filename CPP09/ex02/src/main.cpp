/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:34:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/08 23:54:16 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeVector.hpp"
#include "../inc/PmergeMeDeque.hpp"
#include "../inc/Utils.hpp"
#include <iostream>
#include <cmath>

//Function to calculate theoretical minimum comparisons for Ford-Johnson Algorithm
int calculateTheoreticalComparisons(int n)
{
    if (n <= 1)
        return 0;
    
    if (n == 2)
        return 1;

    //Ford-Johnshon theoretical formula aproximation
    //For n elements, it's roughly n * log2(n) - 2^(log2(n)+1) + n
    double log_n = std::log(static_cast<double>(n)) / std::log(2.0);
    int theoretical = static_cast<int>(n * log_n - std::pow(2.0, static_cast<int>(log_n) + 1) + n);
    return theoretical > 0 ? theoretical : n - 1;
}

int main(int argc, char **argv)
{
    try
    {
        //parse arguments
        std::vector<int> input = Utils::inputParsing(argc, argv);

        Utils::inputValidation(input);

        //Testing vector implementation
        std::cout << "== Testing PmergeMeVector ==" << std::endl;

        PmergeMeVector::resetComparisonCount();

        PmergeMeVector vectorSorter(input);

        //check if vector is empty
        if (vectorSorter.isEmpty())
        {
            std::cout << "Vector is empty!" << std::endl;
            return 1;
        }

        std::cout << "Input size: " << vectorSorter.size() << " elements" << std::endl;

        //sort using the Ford Johnson algorithm
        vectorSorter.sort();

        vectorSorter.printResults();

        //Show comparison analysis
        int actual_comparisons = PmergeMeVector::getComparisonCount();
        int theoretical_min = calculateTheoreticalComparisons(static_cast<int>(input.size()));

        std::cout << "Theoretical minimum comparisons: " << theoretical_min << std::endl;
        std::cout << "Efficiency: " << (actual_comparisons <= theoretical_min * 1.2 ? "GOOD" : "NEEDS IMPROVEMENT") << std::endl;


        //Testing deque implementation
        std::cout << "\n== Testing PmergeMeDeque == " << std::endl;

        //PmergeMeDeque::resetComparisonCount();

        PmergeMeDeque dequeSorter(input);

        if (dequeSorter.isEmpty())
        {
            std::cout << "Deque is empty!" << std::endl;
            return 1;
        }
        
        std::cout << "Input size: " << dequeSorter.size() << " elements" << std::endl;

        dequeSorter.sort();
        dequeSorter.printResults();

        std::cout << "\n== Test completed sucessfully! == " << std::endl;

        //Performance comparison
        std::cout << "\n== Performance Comparison == " << std::endl;
        std::cout << "Vector time: " << vectorSorter.getExecutionTime() << " us" << std::endl;
        std::cout << "Deque time: " << dequeSorter.getExecutionTime() << " us" << std::endl;

        double ratio = vectorSorter.getExecutionTime() / dequeSorter.getExecutionTime();
        std::cout << "Vector / Deque ratio: " << ratio << std::endl;

    }
    catch (std::exception const& e)
    {
        Utils::displayErr(e.what());
        return 1;
    }
        return 0;
}
