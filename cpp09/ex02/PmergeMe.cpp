#include "PmergeMe.hpp"

int checkInput(char* input)
{
	std::vector<int> vector;

	char* token = std::strtok(input, " ");
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

// std::vector<int> parseVector(char* input)
// {
// 	std::vector<int> vector;

// 	char* token = std::strtok(input, " ");
// 	while (token != NULL) {
// 		vector.insert(std::strtoll(token, NULL, 10));
// 		token = std::strtok(input, " ");
// 	}
// 	return vector;
// }


// void printVector(std::vector<int> vector)
// {
//     std::cout << "\n===VECTOR : ===\n";

//     for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); *it++) {
//         std::cout << "token = " << *it << std::endl;
//     }
// }