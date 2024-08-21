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

double PmergeMeV::getTime()
{
	return _time;
}

std::vector<int> PmergeMeV::getOutput()
{
	return _output;
}

void PmergeMeV::printOutputVector()
{
	std::cout << "After (vector): ";

	for (std::vector<int>::iterator it = _output.begin(); it != _output.end(); ++it) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;
}

void PmergeMeV::sort()
{
	std::clock_t start = std::clock();

	if (_vector.size() == 1) {
		_output.push_back(_vector.back());
		std::clock_t end = std::clock();
		_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		return ;
	}

	if (_vector.size() % 2 != 0) {
		_odd = _vector.back(); 
		_vector.pop_back();
	}
	else 
		_odd = -1;

	std::vector<std::pair<int, int> > pairVector = pairElements();
	std::vector<int> jacobsthal = generateJacobsthalSequence(_vector.size());

	sortPairs(pairVector);

	_output.push_back(pairVector[0].first);

	for (size_t i = 0; i < pairVector.size(); i++) {
		_output.push_back(pairVector[i].second);
	}

	for (size_t i = 0; i < jacobsthal.size(); i++) {
		if (static_cast<size_t>(jacobsthal[i] - 1) < pairVector.size()) {
			int index = binarySearch(pairVector[jacobsthal[i] - 1].first);
			_output.insert(_output.begin() + index, pairVector[jacobsthal[i] - 1].first);
		}
	}

	if (_odd != -1) {
		int index = binarySearch(_odd);
		_output.insert(_output.begin() + index, _odd);
	}

	std::clock_t end = std::clock();
	_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

std::vector<std::pair<int, int> > PmergeMeV::pairElements()
{
	std::vector<std::pair<int, int> > pairVector;

	for (size_t i = 0; i < _vector.size() - 1; i += 2) {
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
	int end = _output.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (_output[mid] == a)
			return mid;
		else if (a > _output[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}

	return start;
}

std::vector<int> PmergeMeV::generateJacobsthalSequence(size_t size)
{
    std::vector<int> index;
    int jacobsthalSequence[size + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int last = 2;

    for (size_t i = 2; index.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

		if (i != 2)
			index.push_back(jacobsthalSequence[i]);

        for (int j = jacobsthalSequence[i] - 1; j > last; j--) {
            index.push_back(j);
		}

        last = jacobsthalSequence[i];
    }
    return (index);
}

template <typename T>
void printContainer(T container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << ' ';
	}
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

double PmergeMeL::getTime()
{
	return _time;
}

std::list<int> PmergeMeL::getOutput()
{
	return _output;
}

void PmergeMeL::printOutputList()
{
	std::cout << "After (list): ";

	for (std::list<int>::iterator it = _output.begin(); it != _output.end(); ++it) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;
}

void PmergeMeL::listSort()
{
	std::clock_t start = std::clock();

	if (_list.size() == 1) {
		_output.push_back(_list.back());
		std::clock_t end = std::clock();
		_time = static_cast<double> (end - start) / CLOCKS_PER_SEC;
		return ;
	}

	if (_list.size() % 2 != 0) {
		_odd = _list.back();
		_list.pop_back();
	}
	else 
		_odd = -1;

	std::list<std::pair<int, int> > pairList = listPairElements();
	std::list<int> jacobsthal = generateJacobsthalSequence(_list.size());

	listSortPairs(pairList);

	_output.push_back(pairList.front().first);

	for (std::list<std::pair<int, int> >::iterator it = pairList.begin(); it != pairList.end(); it++) {
		_output.push_back(it->second);
	}

	for (std::list<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++) {
		if (static_cast<size_t>(*it - 1) < pairList.size()) {
			std::list<std::pair<int, int> >::iterator pairIt = pairList.begin();
			std::advance(pairIt, *it -1);
			int index = listBinarySearch(pairIt->first);
			std::list<int>::iterator outputIt = _output.begin();
			std::advance(outputIt, index);
			_output.insert(outputIt, pairIt->first);
		}
	}

	if (_odd != -1) {
		int index = listBinarySearch(_odd);
		std::list<int>::iterator outputIt = _output.begin();
		std::advance(outputIt, index);
		_output.insert(outputIt, _odd);
	}

	std::clock_t end = std::clock();
	_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
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
	int end = _output.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		std::list<int>::iterator itMid = _output.begin();
		std::advance(itMid, mid);
		if (*itMid == a)
			return mid;
		else if (a > *itMid)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return start;
}

std::list<int> PmergeMeL::generateJacobsthalSequence(size_t size)
{
	std::list<int> index;
	int jacobsthalSequence[size + 1];

	jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int last = 2;

    for (size_t i = 2; index.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

		if (i != 2)
			index.push_back(jacobsthalSequence[i]);

        for (int j = jacobsthalSequence[i] - 1; j > last; j--) {
            index.push_back(j);
		}

        last = jacobsthalSequence[i];
    }
    return (index);
}

//ERRORS HANDLING
int checkInput(char* input)
{
	std::vector<int> vector;
	char* errorInput = new char[strlen(input) + 1];
	std::strcpy(errorInput, input);

	char* token = std::strtok(errorInput, " ");
	while (token != NULL) {
		if (!isPositiveInt(token))
			return -1;
		vector.push_back(std::strtoll(token, NULL, 10));
		token = std::strtok(NULL, " ");
	}

	std::sort(vector.begin(), vector.end());
	for (size_t i = 1; i < vector.size(); i++) {
		if (vector[i] == vector[i - 1])
			return -2;
	}

	if (vector.size() <= 1)
		return -3;
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