#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const Point& copy);
        Point(const float a, const float b);
        Point &operator = (const Point& src);
        ~Point();
};

#endif