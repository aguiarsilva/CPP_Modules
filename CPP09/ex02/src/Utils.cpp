/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:17:52 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/04 13:43:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

Utils::Utils() {}

Utils::~Utils() {}

Utils::Utils(Utils const& other)
{}

Utils &Utils::operator=(Utils const& other)
{
    return (*this);
}

//This function should convert args to vector, handle the argc/argv parsing, return a vector for classes Vector and Deque to use
std::vector<int> Utils::inputParsing(int argc, char **argv)
{
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe [positive ints...]");

    std::vector<int> res;
    res.reserver(argc - 1);

    for (int i = 1; i < argc; ++i)
    {
        if (!isValidNum(argv[i]))
        {
            throw std::invalid_argument("Invalid num: " + std::string(argv[i]));
        }

        int num = strToInt(argv[i]);
        res.push_back(num);
    }

    return res;
}

//This function should check for positive ints, handle duplicates, throw exception for invalid data
void Utils::inputValidation(std::vector<int> const& input)
{
    if (input.empty())
        throw std::invalid_argument("Input cannot be empty");

    std::vector<int>::const_iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        if (*it <= 0)
            throw std::invalid_argument("The numbers must be positive");
    }
    //implement check for duplicates
    if (duplicatesCheck(input))
        throw std::invalid_argument("Duplicate numbers not permitted");

    //deal with max size limits?
    if (input.size() > 3000)
        throw std::invalid_argument("Too many elements - Max is 3000");
}

bool Utils::isValidNum(std::string const& str)
{
    if (str.empty())
        return false;i

    if (str.length() > 1 && str[0] == '0')
        return false;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }

    return true;
}

int Utils::strToInt(std::string const& str)
{
    std::istringstream iss(str);
    long res;

    if (!(iss >> res) || !iss.eof())
    {
        throw std::invalid_argument("Invalid integer: " + str);
    }

    if (res > INT_MAX || res < INT_MIN)
    {
        throw std::invalid_argument("Number too large: " + str);    
    }

    return static_cast<int>(res);
}

void Utils::displayErr(std::string const& msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

void Utils::displayVec(std::vector<int> const& vec, std::string const& label)
{
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

bool Utils::duplicatesCheck(std::vector<int> const& input)
{
    for (std::vector<int>::const_iterator it1 = input.begin(); it1 != input.end(); ++it1)
    {
        for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != input.end(); ++it2)
        {
            if (*it1 == *it2)
                return true;
        }
    }
    return false;
}
