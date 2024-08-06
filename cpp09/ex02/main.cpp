#include <iostream>
#include <sys/time.h>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Error. Launch like this : ./PmergeMe \" your list of ints \"";
		return -1;
	}

	(void)argv;

	struct timeval start, vector, list;
	
	gettimeofday(&start, NULL);

	// vectorSort(argv[1]);

	gettimeofday(&vector, NULL);
	double vectorTime = (vector.tv_sec - start.tv_sec) * 1e6 + (vector.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of x elements with std::vector : " << vectorTime << "us" << std::endl;
	
	
	// listSort(argv[1]);

	gettimeofday(&list, NULL);
	double listTime = (list.tv_sec - vector.tv_sec) * 1e6 + (list.tv_usec - vector.tv_usec);
	std::cout << "Time to process a range of x elements with std::list : " << listTime << "us" << std::endl;

	return 0;
}