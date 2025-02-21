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

Point::Point() : x(0), y(0)
{

}

Point::Point(float x, float y) : x(x), y(y)
{

}

Point::Point(Point const& src) : x(src.x), y(src.y)
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
    return (this->x);
}

const Fixed Point::getY() const
{
    return (this->y);
}