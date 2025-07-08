/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:15:56 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:15:56 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int m_fixedPtNum;
        static const int m_fractBitsNum = 8;

    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        Fixed(const int);
        Fixed(const float);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
        bool    operator<(const Fixed& obj) const;
        bool    operator>(const Fixed& obj) const;
        bool    operator<=(const Fixed& obj) const;
        bool    operator>=(const Fixed& obj) const;
        bool    operator==(const Fixed& obj) const;
        bool    operator!=(const Fixed& obj) const;

        Fixed    operator+(const Fixed& obj) const;
        Fixed    operator-(const Fixed& obj) const;
        Fixed    operator/(const Fixed& obj) const;
        Fixed    operator*(const Fixed& obj) const;
    //pre-increment
        Fixed&    operator++();
        Fixed&    operator--();
    //post-increment
        Fixed    operator++(int);
        Fixed    operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& output, const Fixed& src);

#endif