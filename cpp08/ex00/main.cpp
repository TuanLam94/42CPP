#include "easyfind.hpp"
#include <vector>

int main()
{
	std::cout << "====TESTS BEGIN====\n\n";

	std::vector<int> Vector;

	for (int i = 0; i < 7; i++) {
		Vector.push_back(i);
	}

	std::cout << "---looking for 3 in Vector 1 2 3 4 5 6\n";
	int index = easyFind(Vector, 3);
	if (index == -1)
		std::cout << "Did not find 3 in Vector.\n";
	else
		std::cout << "Found 3 in Vector at index " << index << std::endl;

	std::cout << "\n---looking for 8 in Vector 1 2 3 4 5 6\n";
	int index2 = easyFind(Vector, 8);
	if (index2 == -1)
		std::cout << "Did not find 8 in Vector.\n";
	else
		std::cout << "Found 8 in Vector at index " << index2 << std::endl;

	std::cout << "\n\n====TESTS END====\n";

	return 0;
}