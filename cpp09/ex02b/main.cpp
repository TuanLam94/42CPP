#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Error. Launch like this : ./PmergeMe \" your list of ints \"";
		return -1;
	}

	if (!errorHandling(argv[1]))
		return -1;

	PmergeMe<std::vector<int> > Pmerge(argv[1]);

	Pmerge.sort();

	return 0;
}