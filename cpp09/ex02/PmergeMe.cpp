#include "PmergeMe.hpp"

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

void parseVectorList(char* input, std::vector<int>& vector, std::list<int>& list)
{
	char* token = std::strtok(input, " ");
	while (token != NULL) {
		vector.push_back(std::strtoll(token, NULL, 10));
		list.push_back(std::strtoll(token, NULL, 10));
		token = std::strtok(NULL, " ");
	}
}


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