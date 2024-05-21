#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point& copy)
{
    *this = copy;
}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point &Point::operator = (const Point& src)
{
    return *this;
}

Point::~Point() {}