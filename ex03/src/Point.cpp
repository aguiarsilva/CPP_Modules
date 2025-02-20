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