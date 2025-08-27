/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:34:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/27 09:06:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeVector.hpp"
#include "../inc/PmergeMeDeque.hpp"
#include "../inc/Utils.hpp"
#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
    try
    {
        //parse arguments
        std::vector<int> input = Utils::inputParsing(argc, argv);

        Utils::inputValidation(input);

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

        //DEBUG - Show comparison analysis for vector
        //int vector_comparisons = PmergeMeVector::getComparisonCount();
        //int ford_johnson_bound = Utils::calculateFordJohnsonBound(static_cast<int>(input.size()));
        //int info_theoretic_min = Utils::calculateInformationTheoreticMinimum(static_cast<int>(input.size()));

        //DEBUG
        //std::cout << "Information-theoretic minimum: " << info_theoretic_min << std::endl;
        //std::cout << "Ford-Johnson theoretical bound: " << ford_johnson_bound << std::endl;
        //std::cout << "Vector efficiency: " << (vector_comparisons <= ford_johnson_bound ? "EXCELLENT" : 
        //             vector_comparisons <= ford_johnson_bound * 1.2 ? "GOOD" : "NEEDS IMPROVEMENT") << std::endl;

        //Testing deque implementation
        std::cout << "\n== Testing PmergeMeDeque == " << std::endl;

        // Reset comparison count before deque test
        PmergeMeDeque::resetComparisonCount();

        PmergeMeDeque dequeSorter(input);

        if (dequeSorter.isEmpty())
        {
            std::cout << "Deque is empty!" << std::endl;
            return 1;
        }
        
        std::cout << "Input size: " << dequeSorter.size() << " elements" << std::endl;

        dequeSorter.sort();
        dequeSorter.printResults();

        //DEBUG - Show comparison analysis for deque
        //int deque_comparisons = PmergeMeDeque::getComparisonCount();
        //std::cout << "Deque efficiency: " << (deque_comparisons <= ford_johnson_bound ? "EXCELLENT" : 
        //             deque_comparisons <= ford_johnson_bound * 1.2 ? "GOOD" : "NEEDS IMPROVEMENT") << std::endl;

        std::cout << "\n== Test completed successfully! == " << std::endl;

        //DEBUG - Performance comparison
        //std::cout << "\n== Performance Comparison == " << std::endl;
        std::cout << "Vector time: " << vectorSorter.getExecutionTime() << " us" << std::endl;
        std::cout << "Deque time: " << dequeSorter.getExecutionTime() << " us" << std::endl;
        //std::cout << "Vector comparisons: " << vector_comparisons << std::endl;
        //std::cout << "Deque comparisons: " << deque_comparisons << std::endl;

        //if (dequeSorter.getExecutionTime() > 0)
        //{
        //    double ratio = vectorSorter.getExecutionTime() / dequeSorter.getExecutionTime();
        //    std::cout << "Vector / Deque time ratio: " << ratio << std::endl;
        //}

        //if (deque_comparisons > 0)
        //{
        //    double comp_ratio = static_cast<double>(vector_comparisons) / deque_comparisons;
        //    std::cout << "Vector / Deque comparison ratio: " << comp_ratio << std::endl;
        //}

    }
    catch (std::exception const& e)
    {
        Utils::displayErr(e.what());
        return 1;
    }
    return 0;
}