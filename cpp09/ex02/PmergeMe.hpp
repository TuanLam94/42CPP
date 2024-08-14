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
		int					_odd;
		double				_time;

		std::vector<std::pair<int, int> > pairElements();
		void sortPairs(std::vector<std::pair<int, int> > &pairVector);
		int binarySearch(int a);
		std::vector<int> generateJacobsthalSequence(size_t size);

	public:
		PmergeMeV(char* input);
		~PmergeMeV();
		double getTime();
		std::vector<int> getOutput();
		void printOutputVector();
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
		double			_time;

		std::list<std::pair<int, int> > listPairElements();
		void listSortPairs(std::list<std::pair<int, int> > &pairList);
		int listBinarySearch(int a);
		std::list<int> generateJacobsthalSequence(size_t size);

	public:
		PmergeMeL(char* input);
		~PmergeMeL();
		double getTime();
		std::list<int> getOutput();
		void printOutputList();
		void listSort();
};

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p);


template <typename T>
void	printContainer(T container);

int		checkInput(char* input);
bool	errorHandling(char* input);
bool	isPositiveInt(char* token);


#endif