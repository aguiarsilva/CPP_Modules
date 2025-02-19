#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointNum(0)
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
        this->_fixedPointNum = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int value) 
    : _fixedPointNum(value << _fractionalBitsNum)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) 
    : _fixedPointNum(static_cast<int>(roundf(value * (1 << _fractionalBitsNum))))
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
    return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
}

float   Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointNum) / (1 << _fractionalBitsNum);
}

int     Fixed::toInt(void) const
{
    return _fixedPointNum >> _fractionalBitsNum;
}

std::ostream& operator<<(std::ostream& output, const Fixed& src)
{
    output << src.toFloat();
    return output;
}