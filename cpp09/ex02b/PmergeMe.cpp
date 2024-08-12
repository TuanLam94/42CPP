#include "PmergeMe.hpp"

PmergeMeV::PmergeMeV() {}

PmergeMeV::PmergeMeV(const PmergeMeV& rhs)
{
	*this = rhs;
}

PmergeMeV::PmergeMeV(char* input)
{
    std::istringstream iss(input);
    int value;

    while (iss >> value) {
        _vector.push_back(value);
    }
}

PmergeMeV& PmergeMeV::operator = (const PmergeMeV& rhs)
{
	if (this != &rhs) {
		_vector = rhs._vector;
		_odd = rhs._odd;
	}
		
	return *this;
}

PmergeMeV::~PmergeMeV() {}

void PmergeMeV::sort()
{
	// std::clock_t start = std::clock();

	if (_vector.size() % 2 != 0)
		_odd = _vector.back();
	else 
		_odd = -1;

	std::vector<std::pair<int, int> > pairVector = pairElements();

	sortPairs(pairVector);

	_output.push_back(pairVector[pairVector.size() - 1].second);

	printContainer(pairVector);
	printContainer(_output);

}

std::vector<std::pair<int, int> > PmergeMeV::pairElements()
{
	std::vector<std::pair<int, int> > pairVector;

	for (size_t i = 0; i < _vector.size(); i += 2) {
		if (_vector[i] > _vector[i + 1])
			std::swap(_vector[i], _vector[i + 1]);

		pairVector.push_back(std::make_pair(_vector[i], _vector[i + 1]));
	}

	return pairVector;
}

void PmergeMeV::sortPairs(std::vector<std::pair<int, int> > &pairVector)
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

int PmergeMeV::binarySearch(int a)
{
	int start = 0;
	int end = _vector.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (_vector[mid] == a)
			return mid;
		else if (a > _vector[mid])
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

std::ostream& operator << (std::ostream& os, const std::pair<int, int>& p)
{
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}


//	===========		LIST IMPLEMENTATION		==================

PmergeMeL::PmergeMeL() {}

PmergeMeL::PmergeMeL(const PmergeMeL& rhs)
{
	*this = rhs;
}

PmergeMeL::PmergeMeL(char* input)
{
    std::istringstream iss(input);
    int value;

    while (iss >> value) {
        _list.push_back(value);
    }
}

PmergeMeL& PmergeMeL::operator = (const PmergeMeL& rhs)
{
	if (this != &rhs) {
		_list = rhs._list;
		_odd = rhs._odd;
	}
		
	return *this;
}

PmergeMeL::~PmergeMeL() {}

void PmergeMeL::listSort()
{
	// std::clock_t start = std::clock();

	if (_list.size() % 2 != 0)
		_odd = _list.back();
	else 
		_odd = -1;

	std::list<std::pair<int, int> > pairList = listPairElements();

	listSortPairs(pairList);

	_output.push_back(pairList.back().second);

	printContainer(pairList);
	printContainer(_output);

}

std::list<std::pair<int, int> > PmergeMeL::listPairElements()
{
	std::list<std::pair<int, int> > pairList;
	std::list<int>::iterator it = _list.begin();

	while (it != _list.end()) {
		std::list<int>::iterator next = it;
		std::advance(next, 1);
		if (next == _list.end())
			break;
		
		if (*it > *next)
			std::swap(*it, *next);

		pairList.push_back(std::make_pair(*it, *next));

		std::advance(it, 2);
	}

	return pairList;
}

void PmergeMeL::listSortPairs(std::list<std::pair<int, int> > &pairList)
{
	if (pairList.size() <= 1)
		return;

    std::list<std::pair<int, int> >::iterator mid = pairList.begin();
    std::advance(mid, pairList.size() / 2);

	std::list<std::pair<int, int> > leftSide(pairList.begin(), mid);
	std::list<std::pair<int, int> > rightSide(mid, pairList.end());

	listSortPairs(leftSide);
	listSortPairs(rightSide);

	pairList.clear();

	std::list<std::pair<int, int> >::iterator leftIt = leftSide.begin();
	std::list<std::pair<int, int> >::iterator rightIt = rightSide.begin();


	while (leftIt != leftSide.end() && rightIt != rightSide.end()) {
		if (leftIt->second < rightIt->second)
			pairList.push_back(*leftIt++);
		else
			pairList.push_back(*rightIt++);
	}

	while (leftIt != leftSide.end()) {
		pairList.push_back(*leftIt++);
	}

	while (rightIt != rightSide.end()) {
		pairList.push_back(*rightIt++);
	}
}

int PmergeMeL::listBinarySearch(int a)
{
	int start = 0;
	int end = _list.size() - 1;
	
	while (start <= end) {
		int mid = (start + end) / 2;
		std::list<int>::iterator itMid = _list.begin();
		std::advance(itMid, mid);
		if (*itMid == a)
			return mid;
		else if (a > *itMid)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
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

// template class PmergeMe<std::vector<int> >;
// template class PmergeMe<std::deque<int> >;

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