#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point &Point::operator = (const Point& src)
{
	if (*this == src)
		return *this;
    return *this;
}

bool Point::operator == (const Point& other) const
{
	return (this->x == other.x && this->y == other.y);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

Point::~Point() {}