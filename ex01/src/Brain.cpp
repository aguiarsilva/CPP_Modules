/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:21:09 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/30 23:21:11 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Brain copy constructor" << std::endl;
    *this = obj;
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignement operator" << std::endl;
    if (this != &other)
       for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    return *this;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 0 && i < 100)
        return ideas[i];
    return "";
}

void Brain::setIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}
