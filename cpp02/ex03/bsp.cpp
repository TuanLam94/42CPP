#include "Fixed.hpp"
#include "Point.hpp"

static Fixed  abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return x;
}

static Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area = abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	return area;
}

bool cross(const Point& a, const Point& b, const Point& point)
{
	Fixed dxc = point.getX() - a.getX();
	Fixed dyc = point.getY() - a.getY();

	Fixed dxl = b.getX() - a.getX();
	Fixed dyl = b.getY() - a.getY();

	Fixed cross = dxc * dyl - dyc * dxl;

	if (cross != Fixed(0))
		return false;
	
	if (abs(dxl) >= abs(dyl))
		return dxl > Fixed(0) ? a.getX() <= point.getX() && point.getX() <= b.getX() : 
			b.getX() <= point.getX() && point.getX() <= a.getX();
	else
		return dyl > Fixed(0) ? a.getY() <= point.getY() && point.getY() <= b.getY() :
			b.getY() <= point.getY() && point.getY() <= a.getY();

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (a == b || a == c || b == c) {
		std::cout << "Error, invalid triangle\n";
		return false;
	}
	if (point == a || point == b || point == c) {
		std::cout << "Error, point is a vertex\n";
		return false;
	}
	if (cross(a, b, point) || cross (a, c, point) || cross(b, c, point)) {
		std::cout << "Error, point is on an edge\n";
		return false;
	}

	Fixed areaABC = area(a, b, c);
	Fixed areaABP = area(a, b, point);
	Fixed areaACP = area(a, c, point);
	Fixed areaBCP = area(b, c, point);

	return areaABC == (areaABP + areaACP + areaBCP);
}

