/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:48 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/06 14:55:54 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
    private:
        size_t arrSize;
        T* arrContents;

    public:
        Array();
        Array(size_t arrSize);
        Array(Array<T> const& other);
        Array &operator=(Array<T> const& other);
        T &operator[](size_t index);
        const T &operator[](size_t index) const;
        ~Array();

        size_t size() const;
};

#include "Array.tpp"

#endif
