/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:09:48 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:09:48 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed 
{
    private:
        int m_fixedPtNum;
        static const int m_fractBitsNum = 8;

    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif
