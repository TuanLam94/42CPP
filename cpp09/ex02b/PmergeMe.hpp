#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <limits.h>
#include <utility>
#include <iterator>

class PmergeMeV
{
	private:
		PmergeMeV();
		PmergeMeV(const PmergeMeV &rhs);
		PmergeMeV &operator = (const PmergeMeV &rhs);

		std::vector<int>	_vector;
		std::vector<int>	_output;
		int				_odd;

		std::vector<std::pair<int, int> > pairElements();
		void sortPairs(std::vector<std::pair<int, int> > &pairVector);
		int binarySearch(int a);

	public:
		PmergeMeV(char* input);
		~PmergeMeV();
		void sort();
};

class PmergeMeL
{
	private:
		PmergeMeL();
		PmergeMeL(const PmergeMeL &rhs);
		PmergeMeL &operator = (const PmergeMeL &rhs);

		std::list<int>	_list;
		std::list<int>	_output;
		int				_odd;

		std::list<std::pair<int, int> > listPairElements();
		void listSortPairs(std::list<std::pair<int, int> > &pairList);
		int listBinarySearch(int a);

	public:
		PmergeMeL(char* input);
		~PmergeMeL();
		void listSort();
};

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p);

std::vector<int> generateJacobsthalSequence(size_t size);

template <typename T>
void	printContainer(T container);

int		checkInput(char* input);
bool	errorHandling(char* input);
bool	isPositiveInt(char* token);


#endif