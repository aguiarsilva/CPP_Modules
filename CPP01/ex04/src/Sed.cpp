/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:58:10 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:58:10 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>
#include <fstream>

//public methods
Sed::Sed(const std::string& file, const std::string& s1, const std::string& s2)
    : fileName(file), searchString(s1), replaceString(s2)
{

}

bool Sed::replaceStr()
{
    if (!validateArgs())
        return false;

    std::ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        std::cout << "Error: Failed to open input file: " << fileName << std::endl;
        return false;
    }

    std::string outputFile = fileName + ".replace";
    std::ofstream outFile(outputFile.c_str());
    if (!outFile)
    {
        std::cout << "Error: Failed to open output file: " << outputFile << std::endl;
        inFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        outFile << replaceExec(line);
        if (!inFile.eof())
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();

    return true;
}

//private methods
bool Sed::validateArgs() const
{
    if (fileName.empty() || searchString.empty())
    {
        std::cout << "Error: Empty filename or search string!" << std::endl;
        return false;
    }
    return true;
}

std::string Sed::replaceExec(const std::string& line) const
{
    std::string result;
    size_t startPos = 0;
    size_t findPos;
    
    while((findPos = line.find(searchString, startPos)) != std::string::npos)
    {
        result.append(line, startPos, findPos - startPos);
        result.append(replaceString);
        startPos = findPos + searchString.length();
    }    
    result.append(line.substr(startPos));

    return result;
}
