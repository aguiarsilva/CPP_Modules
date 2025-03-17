/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:16:26 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 15:16:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : m_x(0), m_y(0)
{

}

Point::Point(float x, float y) : m_x(x), m_y(y)
{

}

Point::Point(Point const& src) : m_x(src.m_x), m_y(src.m_y)
{

}

Point::~Point()
{

}

Point& Point::operator=(Point const& obj)
{
    (void)obj;
    return *this;
}

const Fixed Point::getX() const
{
    return (this->m_x);
}

const Fixed Point::getY() const
{
    return (this->m_y);
}