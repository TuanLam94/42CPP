#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point const a(1, 3), b(1,5), c(5,3), p(2,4);

	if (bsp(a, b, c, p) == true)
		std::cout << "true !\n";
	else
		std::cout << "false !\n";
	return 0;
}