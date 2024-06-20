#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "===TESTS BEGIN====\n\n";

	std::cout << "--checking no parameter constructor, should see 0 : \n\n";

	Array <int>a;

	std::cout << a.size() << std::endl;

	std::cout << "\n ---checking array of int of size 5 : \n\n";

	Array <int>b(5);
	std::cout << "array size : " << b.size() << std::endl;

	std::cout << "\n----now printing array b----\n\n";

	std::cout << b << std::endl;

	std::cout << "\n----now allocating array b and printing again, should see 1 2 3 4 5----\n\n";

	for (size_t i = 0; i < b.size(); i++) {
		b[i] = i + 1;
	}

	std::cout << b << std::endl;

	std::cout << "\n ---checking array of strings of size 5 : \n\n";

	Array <std::string>c(5);
	std::cout << "array c size : " << c.size() << std::endl;

	std::cout << "\n----now printing array c----\n\n";

	std::cout << c << std::endl;

	std::cout << "\n----now allocating array c and printing again, should see 1 2 3 4 5----\n\n";

	for (size_t i = 0; i < b.size(); i++) {
		c[i] = i + '1';
	}

	std::cout << c << std::endl;

	std::cout << "\n====TESTS END====\n";

	return 0;
}