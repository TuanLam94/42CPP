#include "PmergeMe.hpp"

//VECTOR SORT
void vectorSort(std::vector<int>& vector)
{
	int isOdd;

	if (vector.size() % 2 != 0) {
		isOdd = vector.back();
		vector.pop_back();
	}
	else
		isOdd = 0;

	(void)isOdd;

	int n = vector.size();
	sortEachPair(vector);
	vectorMergeInsertSort(vector, 0, n);


	// insertOdd(vector, isOdd);
	printVector(vector);
}

void vectorMergeInsertSort(std::vector<int>& vector, int start, int end)
{
	std::vector<int> largerElements;
	std::vector<int> smallerElements;

	std::vector<int> result;

	if (vector.size() <= 1)
		return ;

	//pair elements until one pair remaining
	for (size_t i = 0; i < vector.size() - 1; i++) {
		if (vector[i] > vector[i + 1]) {
			largerElements.push_back(vector[i]);
			smallerElements.push_back(vector[i + 1]);
		}
		else {
			largerElements.push_back(vector[i + 1]);
			smallerElements.push_back(vector[i]);
		}
	}

	vectorMergeInsertSort(largerElements);

	//insert smaller elements in larger elements HERE

	result.insert(0, largerElements[0]);

	for (size_t i = 0; i < smallerElements.size() - 1; i++) {
		if (i = 0)
			result.
	}
}

//PARSING
void parseVectorList(char* input, std::vector<int>& vector, std::list<int>& list)
{
	char* token = std::strtok(input, " ");
	while (token != NULL) {
		vector.push_back(std::strtoll(token, NULL, 10));
		list.push_back(std::strtoll(token, NULL, 10));
		token = std::strtok(NULL, " ");
	}
}

//UTILS
void printVector(std::vector<int> vector)
{
    std::cout << "\n=== VECTOR : ===\n";

    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); *it++) {
        std::cout << "token = " << *it << std::endl;
    }
}

void printList(std::list<int> list)
{
    std::cout << "\n=== LIST : ===\n";

    for (std::list<int>::iterator it = list.begin(); it != list.end(); *it++) {
        std::cout << "token = " << *it << std::endl;
    }
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