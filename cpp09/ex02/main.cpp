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

	PmergeMeL PmergeMeL(argv[1]);
	PmergeMeL.listSort();

	std::cout << "Before: " << argv[1] << std::endl;
	PmergeMeV.printOutputVector();

	std::cout << "After (list): ";
	PmergeMeL.printOutputList();

	std::cout << "Time to process a range of " << PmergeMeV.getOutput().size() 
		<< " elements with std::vector<int> : " << PmergeMeV.getTime() << std::endl;
	std::cout << "Time to process a range of " << PmergeMeL.getOutput().size() 
		<< " elements with std::list<int> : " << PmergeMeL.getTime() << std::endl;

	return 0;
}