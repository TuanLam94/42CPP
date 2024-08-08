#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Error. Launch like this : ./PmergeMe \" your list of ints \"";
		return -1;
	}

	if (!errorHandling(argv[1]))
		return -1;

	std::vector<int> vector;
	std::list<int> list;
	parseVectorList(argv[1], vector, list);

	struct timeval start, vectortv, listtv;
	
	gettimeofday(&start, NULL);

	printVector(vector);
	// printList(list);

	vectorSort(vector);

	gettimeofday(&vectortv, NULL);
	double vectorTime = (vectortv.tv_sec - start.tv_sec) * 1e6 + (vectortv.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of x elements with std::vector : " << vectorTime << "us" << std::endl;
	
	
	// listSort(argv[1]);

	gettimeofday(&listtv, NULL);
	double listTime = (listtv.tv_sec - vectortv.tv_sec) * 1e6 + (listtv.tv_usec - vectortv.tv_usec);
	std::cout << "Time to process a range of x elements with std::list : " << listTime << "us" << std::endl;

	return 0;
}