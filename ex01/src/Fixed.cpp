/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:15:24 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:15:24 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_fixedPtNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->m_fixedPtNum = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int value) 
    : m_fixedPtNum(value << m_fractBitsNum)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) 
    : m_fixedPtNum(static_cast<int>(roundf(value * (1 << m_fractBitsNum))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->m_fixedPtNum;
}

void Fixed::setRawBits(int const raw)
{
    this->m_fixedPtNum = raw;
}

float   Fixed::toFloat(void) const
{
    return static_cast<float>(m_fixedPtNum) / (1 << m_fractBitsNum);
}

int     Fixed::toInt(void) const
{
    return m_fixedPtNum >> m_fractBitsNum;
}

std::ostream& operator<<(std::ostream& output, const Fixed& src)
{
    output << src.toFloat();
    return output;
}