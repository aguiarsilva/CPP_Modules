/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:20:18 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/15 09:11:37 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <limits>

class Span
{
    private:
        unsigned int m_number;
        std::vector<int> m_vec;

    public:
        Span(unsigned int n);
        Span(Span const& other);
        Span &operator=(Span const& other);
        ~Span();

        void addNumber(int val);
        int shortestSpan() const;
        int longestSpan() const;
        template <typename Iterator> void addNumbers(Iterator begin, Iterator end);

        class MaxCapacity  : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: Maximum Capacity of the container reached!");
                }
        };

        class InsufficientElementsException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: Container has less than 2 elements!");
                }
        };
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    for (Iterator it = begin; it != end; ++it)
    {
        addNumber(*it);   
    }
}

#endif
