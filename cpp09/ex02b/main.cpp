#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Error. Launch like this : ./PmergeMe \" your list of ints \"";
		return -1;
	}

	if (!errorHandling(argv[1]))
		return -1;

	PmergeMeV PmergeMeV(argv[1]);
	PmergeMeV.sort();

	// PmergeMeL PmergeMeL(argv[1]);
	// PmergeMeL.listSort();

	return 0;
}