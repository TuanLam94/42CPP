#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <limits.h>
#include <utility>
#include <iterator>

template <typename Container>
class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator = (const PmergeMe &rhs);

		Container	_container;
		Container	_output;
		int				_odd;

		std::vector<std::pair<int, int> > pairElements(Container& container);
		void sortPairs(std::vector<std::pair<int, int> > &pairVector);
		int binarySearch(int a);
	public:
		PmergeMe(char* input);
		~PmergeMe();
		void sort();
};

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p);

template <typename T>
void printContainer(T container);

int checkInput(char* input);
bool errorHandling(char* input);
bool isPositiveInt(char* token);


#endif