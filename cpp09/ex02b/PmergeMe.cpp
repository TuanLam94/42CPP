#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(char* input)
{
	char* token = std::strtok(input, " ");
	while (token != NULL) {
		_container.push_back(std::strtoll(token, NULL, 10));
		token = std::strtok(NULL, " ");
	}
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator = (const PmergeMe& rhs)
{
	if (this != &rhs) {
		_container = rhs._container;
		_odd = rhs._odd;
	}
		
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void PmergeMe<Container>::sort()
{
	// std::clock_t start = std::clock();

	if (_container.size() % 2 != 0)
		_odd = _container.back();
	else 
		_odd = -1;

	std::vector<std::pair<int, int> > pairVector = pairElements(_container);

	sortPairs(pairVector);

	_output.push_back(pairVector[pairVector.size() - 1].second);

	printContainer(pairVector);
	printContainer(_output);

}

template <typename Container>
std::vector<std::pair<int, int> > PmergeMe<Container>::pairElements(Container& container)
{
	std::vector<std::pair<int, int> > pairVector;

	for (size_t i = 0; i < _container.size(); i += 2) {
		if (_container[i] > _container[i + 1])
			std::swap(_container[i], container[i + 1]);

		pairVector.push_back(std::make_pair(_container[i], _container[i + 1]));
	}

	return pairVector;
}

template <typename Container>
void PmergeMe<Container>::sortPairs(std::vector<std::pair<int, int> > &pairVector)
{
	if (pairVector.size() <= 1)
		return;
	size_t mid = pairVector.size() / 2;

	std::vector<std::pair<int, int> > leftSide(pairVector.begin(), pairVector.begin() + mid);
	std::vector<std::pair<int, int> > rightSide(pairVector.begin() + mid, pairVector.end());

	sortPairs(leftSide);
	sortPairs(rightSide);

	size_t i = 0, j = 0, k = 0;

	while (i < leftSide.size() && j < rightSide.size()) {
		if (leftSide[i].second < rightSide[j].second)
			pairVector[k++] = leftSide[i++];
		else
			pairVector[k++] = rightSide[j++];
	}

	while (i < leftSide.size()) {
		pairVector[k++] = leftSide[i++];
	}

	while (j < rightSide.size()) {
		pairVector[k++] = rightSide[j++];
	}
}

template <typename Container>
int PmergeMe<Container>::binarySearch(int a)
{
	int start = 0;
	int end = _container.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (_container[mid] == a)
			return mid;
		else if (a > _container[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}

std::vector<int> generateJacobsthalSequence(int limit)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	int i = 2;
	for (int j = 0; j < limit; j++) {
		int next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
	}

	return jacob;
}

template <typename T>
void printContainer(T container)
{
	std::cout << "\n=== Container : ===\n";

	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p)t(
        make_
{
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}

//ERRORS HANDLING
int checkInput(char* input)
{
	std::vector<int> vector;
	char* errorInput = new char[strlen(input) + 1];
	std::strcpy(errorInput, input);

	char* token = std::strtok(errorInput, " ");
	while (token != NULL) {
		if (!isPositiveInt(token)) {

			return -1;
		}
		vector.push_back(std::strtoll(token, NULL, 10));
		token = std::strtok(NULL, " ");
	}

	std::sort(vector.begin(), vector.end());
	for (size_t i = 1; i < vector.size(); i++) {
		if (vector[i] == vector[i - 1]) {

			return -2;
		}
	}

	if (vector.size() <= 1)
	{
		return -3;
	}
	return 1;
}

bool errorHandling(char* input)
{
	int error = checkInput(input);

	switch(error) {
		case -1:
			std::cout << "Error, input must be a list of positive ints" << std::endl;
			return false;
		case -2:
			std::cout << "Error, input must not contain any duplicates" << std::endl;
			return false;
		case -3:
			std::cout << "Error, input must contain more than one int" << std::endl;
			return false;
		case 1:
			return true;
	}
	return true;
}

bool isPositiveInt(char* token)
{
	int i = 0;
	while (token[i] != '\0') {
		if (!isdigit(token[i]))
			return false;
		i++;
	}

	int res = std::strtoll(token, NULL, 10);
	if (res > INT_MAX || res <= 0)
		return false;

	return true;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

// //UTILS
// void printVector(std::vector<int> vector)
// {
//     std::cout << "\n=== VECTOR : ===\n";

//     for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); *it++) {
//         std::cout << "token = " << *it << std::endl;
//     }
// }

// void printList(std::list<int> list)
// {
//     std::cout << "\n=== LIST : ===\n";

//     for (std::list<int>::iterator it = list.begin(); it != list.end(); *it++) {
//         std::cout << "token = " << *it << std::endl;
//     }
// }