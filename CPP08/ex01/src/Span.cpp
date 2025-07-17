/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:50:53 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/15 09:18:39 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int n) : m_number(n), m_vec()
{
    m_vec.reserve(n);
}

Span::Span(Span const& other) : m_number(other.m_number), m_vec(other.m_vec)
{}

Span &Span::operator=(Span const& other)
{
    if (this != &other)
    {
        this->m_number = other.m_number;
        this->m_vec = other.m_vec;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int val)
{
    if (m_vec.size() != m_number)
    {
        m_vec.push_back(val);
    }
    else
    {
        throw Span::MaxCapacity();
    }
}

int Span::shortestSpan() const
{
    if (m_vec.size() < 2)
        throw InsufficientElementsException();
    
    std::vector<int> toSort = m_vec;
    std::sort(toSort.begin(), toSort.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i != toSort.size() - 1; i++)
    {
        int temp = toSort[i + 1] - toSort[i];
        if (minSpan > temp)
            minSpan = temp;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (m_vec.size() < 2)
        throw InsufficientElementsException();

    std::vector<int> toSort = m_vec;
    std::sort(toSort.begin(), toSort.end());

    return toSort[toSort.size() - 1] - toSort[0];
}
