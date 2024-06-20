#include <iostream>
#include "iter.hpp"

void printInt(int& x)
{
	std::cout << x << std::endl;
}

void printString(std::string& str)
{
	std::cout << str << std::endl;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5, 6};
	size_t intLength = 6;

	std::cout << "Printing array 1 2 3 4 5 6 now : \n\n";

	iter(intArray, intLength, printInt);

	std::string stringArray[] = {"bonjour", "a", "tous"};
	size_t stringLength = 3;

	std::cout << "Printing string array : bonjour a tous now : \n\n";

	iter(stringArray, stringLength, printString);

	return 0;
}