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
		PmergeMe() {}
		PmergeMe(const PmergeMe &rhs) {*this = rhs;}
		PmergeMe &operator = (const PmergeMe &rhs) {
			if (this != &rhs) {
				_container = rhs._container;
				_odd = rhs._odd;
			}
			return *this;
		}

		Container	_container;
		Container	_output;
		int				_odd;

		std::vector<std::pair<int, int> > pairElements(Container& container);
		void sortPairs(std::vector<std::pair<int, int> > &pairVector);
		int binarySearch(int a);

	public:
		PmergeMe(char* input) {
			char* token = std::strtok(input, " ");
			while (token != NULL) {
				_container.push_back(std::strtoll(token, NULL, 10));
				token = std::strtok(NULL, " ");
			}

			if (_container.size() % 2 != 0)
				_odd = _container.back();
			else 
				_odd = -1;	
		}

		~PmergeMe();
		void sort() {
			std::vector<std::pair<int, int> > pairVector = pairElements(_container);

			sortPairs(pairVector);

			printContainer(pairVector);
		}
		void print() const {
			std::cout << "\n=== Container : ===\n";

			typename Container::const_iterator it;
			for (it = _container.begin(); it != _container.end(); ++it) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
		}
};

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p);

template <typename T>
void printContainer(T container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); *it++) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

int checkInput(char* input);
bool errorHandling(char* input);
bool isPositiveInt(char* token);

#endif