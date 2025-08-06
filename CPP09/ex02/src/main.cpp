/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:34:08 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/06 13:31:24 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeVector.hpp"
#include "../inc/PmergeMeDeque.hpp"
#include "../inc/Utils.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        //parse arguments
        std::vector<int> input = Utils::inputParsing(argc, argv);

        Utils::inputValidation(input);

        //Testing vector implementation
        std::cout << "== Testing PmergeMeVector ==" << std::endl;

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

        std::cout << "\n== Test completed sucessfully! == " << std::endl;

    }
    catch (std::exception const& e)
    {
        Utils::displayErr(e.what());
        return 1;
    }
        return 0;
}
