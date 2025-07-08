/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:16:18 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:16:18 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_fixedPtNum(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->m_fixedPtNum = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int value) 
    : m_fixedPtNum(value << m_fractBitsNum)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) 
    : m_fixedPtNum(static_cast<int>(roundf(value * (1 << m_fractBitsNum))))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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

bool    Fixed::operator<(const Fixed& obj) const
{
    return this->m_fixedPtNum < obj.m_fixedPtNum;
}

bool    Fixed::operator>(const Fixed& obj) const
{
    return this->m_fixedPtNum > obj.m_fixedPtNum;
}

bool    Fixed::operator<=(const Fixed& obj) const
{
    return this->m_fixedPtNum <= obj.m_fixedPtNum;
}

bool    Fixed::operator>=(const Fixed& obj) const
{
    return this->m_fixedPtNum >= obj.m_fixedPtNum;
}

bool    Fixed::operator==(const Fixed& obj) const
{
    return this->m_fixedPtNum == obj.m_fixedPtNum;
}

bool    Fixed::operator!=(const Fixed& obj) const
{
    return this->m_fixedPtNum != obj.m_fixedPtNum;
}

Fixed    Fixed::operator+(const Fixed& obj) const
{
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed    Fixed::operator-(const Fixed& obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed    Fixed::operator/(const Fixed& obj) const
{
    if (obj.m_fixedPtNum == 0)
    {
        std::cout << "Error: Cannot divide by 0" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / obj.toFloat());
}

Fixed    Fixed::operator*(const Fixed& obj) const
{
   return Fixed(this->toFloat() * obj.toFloat());
}

Fixed&    Fixed::operator++()
{
    ++m_fixedPtNum;
    return *this;
}

Fixed&    Fixed::operator--()
{
    --m_fixedPtNum;
    return *this;
}

Fixed    Fixed::operator++(int)
{
    Fixed copy = *this;
    m_fixedPtNum++;
    return copy;
}

Fixed    Fixed::operator--(int)
{
    Fixed copy = *this;
    m_fixedPtNum--;
    return copy;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}