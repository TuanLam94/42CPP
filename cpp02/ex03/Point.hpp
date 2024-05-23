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
		bool operator==(const Point& other) const;
		Fixed getX(void) const;
		// void setX(Fixed x);
		Fixed getY(void) const;
		// void setY(Fixed y);
        ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
bool cross(const Point& a, const Point& b, const Point& point);

#endif