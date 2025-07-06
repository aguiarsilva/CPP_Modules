/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:09:01 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/06 13:55:53 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T&))
{
    //std::cout << "[DEBUG] - Using const overload" << std::endl;
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(T *array, size_t length, void (*func)(T&))
    {
        //std::cout << "[DEBUG] - Using non-const overload" << std::endl;
        for (size_t i = 0; i < length; i++)
        {
            func(array[i]);
        }
    }

#endif
