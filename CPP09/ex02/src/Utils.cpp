/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:17:52 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/19 22:28:38 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

Utils::Utils() {}

Utils::~Utils() {}

Utils::Utils(Utils const& other)
{
    (void)other;
}

Utils &Utils::operator=(Utils const& other)
{
    (void)other;
    return (*this);
}

//This function should convert args to vector, handle the argc/argv parsing, return a vector for classes Vector and Deque to use
std::vector<int> Utils::inputParsing(int argc, char **argv)
{
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe [unique positive ints...]");

    std::vector<int> res;
    res.reserve(argc - 1); // Pre-allocate memory

    int i;
    for (i = 1; i < argc; ++i)
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

    // Check for duplicates - optimized version
    //if (duplicatesCheck(input))
    //    throw std::invalid_argument("Duplicate numbers not permitted");

    // Deal with max size limits
    if (input.size() > 3000)
        throw std::invalid_argument("Too many elements - Max is 3000");
}

bool Utils::isValidNum(std::string const& str)
{
    if (str.empty())
        return false;

    // Check for leading zeros (except single "0" which we don't want anyway since we need positive)
    if (str.length() > 1 && str[0] == '0')
        return false;

    // Don't allow just "0" since we need positive numbers
    if (str == "0")
        return false;

    std::string::const_iterator it;
    for (it = str.begin(); it != str.end(); ++it)
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
    std::cout << label;
    
    // Limit output for very large vectors
    if (vec.size() > 20)
    {
        std::vector<int>::const_iterator it;
        int count = 0;
        for (it = vec.begin(); it != vec.end() && count < 10; ++it, ++count)
        {
            std::cout << *it << " ";
        }
        std::cout << "[...] ";
        
        // Show last few elements
        for (it = vec.end() - 5; it != vec.end(); ++it)
        {
            std::cout << *it;
            if (it + 1 != vec.end())
                std::cout << " ";
        }
    }
    else
    {
        std::vector<int>::const_iterator it;
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it;
            if (it + 1 != vec.end())
                std::cout << " ";
        }
    }
    std::cout << std::endl;
}

// Optimized duplicate check using sorting approach for larger inputs
// bool Utils::duplicatesCheck(std::vector<int> const& input)
// {
//     if (input.size() < 2)
//         return false;

//     // For small inputs, use simple O(n²) approach
//     if (input.size() <= 100)
//     {
//         std::vector<int>::const_iterator it1;
//         for (it1 = input.begin(); it1 != input.end(); ++it1)
//         {
//             std::vector<int>::const_iterator it2;
//             for (it2 = it1 + 1; it2 != input.end(); ++it2)
//             {
//                 if (*it1 == *it2)
//                     return true;
//             }
//         }
//         return false;
//     }

//     // For larger inputs, use sorting approach O(n log n)
//     std::vector<int> sorted_copy = input;
//     std::sort(sorted_copy.begin(), sorted_copy.end());

//     std::vector<int>::const_iterator it;
//     for (it = sorted_copy.begin(); it != sorted_copy.end() - 1; ++it)
//     {
//         if (*it == *(it + 1))
//             return true;
//     }

//     return false;
// }

//Helper test functions to determine the Approximate theoretical minimum comparisons and the upper bound comparisons according to Ford-Johnson Algorithm
//Function to calculate Ford-Johnson theoretical upper bound
int Utils::calculateFordJohnsonBound(int n)
{
    if (n <= 1)
        return 0;
    
    if (n == 2)
        return 1;

    if (n == 3)
        return 3;

    // More accurate Ford-Johnson bound calculation
    // Based on: n*log2(n) - 2^(⌊log2(n)⌋+1) + n + O(log n)
    double log_n = std::log(static_cast<double>(n)) / std::log(2.0);
    int floor_log = static_cast<int>(log_n);
    
    // Ford-Johnson bound: n*log2(n) - 2^(⌊log2(n)⌋+1) + n
    int theoretical = static_cast<int>(n * log_n - std::pow(2.0, floor_log + 1) + n + log_n);
    
    return theoretical > 0 ? theoretical : n - 1;
}

// Calculate information-theoretic minimum (any sorting algorithm)
int Utils::calculateInformationTheoreticMinimum(int n)
{
    if (n <= 1)
        return 0;
    
    // Stirling's approximation for log2(n!)
    // log2(n!) ≈ n*log2(n) - n*log2(e) + O(log n)
    double log_factorial = 0.0;
    int i;
    for (i = 2; i <= n; ++i)
    {
        log_factorial += std::log(static_cast<double>(i)) / std::log(2.0);
    }
    
    return static_cast<int>(std::ceil(log_factorial));
}