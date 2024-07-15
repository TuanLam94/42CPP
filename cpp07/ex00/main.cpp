#include <iostream>
#include "max.hpp"
#include "min.hpp"
#include "swap.hpp"

int main()
{
	std::cout << "===SUBJECT TESTS===\n\n";

	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "Swapping...\n";

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\nnow with strings :\n";

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "Swapping...\n";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	return 0;
}

