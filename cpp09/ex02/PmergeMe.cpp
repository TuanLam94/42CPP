#include "PmergeMe.hpp"

//VECTOR SORT
void vectorSort(std::vector<int>& vector)
{
	// int isOdd;

	// if (vector.size() % 2 != 0) {
	// 	isOdd = vector.back();
	// 	vector.pop_back();
	// }
	// else
	// 	isOdd = 0;

	// (void)isOdd;

	int n = vector.size();

	vectorMergeInsertSort(vector, 0, n);
	// insertOdd(vector, isOdd);
	// printVector(vector);
}

void vectorMergeInsertSort(std::vector<int>& vector, int start, int end)
{
	int n = end - start;

	if (n <= 1)
		return ;

	int mid = start + n /2;

	std::vector<int> largerElements(mid - start);
	std::vector<int> smallerElements(mid - start);

	//first pair them

	for (int i = 0; i < mid - start; i++) {
        int leftElement = vector[start + i];
        int rightElement = vector[mid + i];

	//put them in vectors
        if (leftElement < rightElement) {
            smallerElements[i] = leftElement;
            largerElements[i] = rightElement;
        } else {
            smallerElements[i] = rightElement;
            largerElements[i] = leftElement;
        }
    }

    vectorMergeInsertSort(largerElements, 0, mid - start);
    vectorMergeInsertSort(smallerElements, 0, mid - start);


	std::cout << "\nsmaller:";
	printVector(smallerElements);
	std::cout << "\nlarger:";
	printVector(largerElements);

    int i = 0, j = 0, k = start;
    while (i < mid - start && j < mid - start) {
        if (smallerElements[i] < largerElements[j]) {
            vector[k++] = smallerElements[i++];
        } else {
            vector[k++] = largerElements[j++];
        }
    }

    while (i < mid - start) {
        vector[k++] = smallerElements[i++];
    }

    while (j < mid - start) {
        vector[k++] = largerElements[j++];
    }
}




void sortEachPair(std::vector<int>& vector)
{
	for (size_t i = 0; i < vector.size(); i += 2) {
		int temp;
		if (vector[i] > vector[i + 1]) {
			temp = vector[i];
			vector[i] = vector[i + 1];
			vector[i + 1] = temp;
		}
	}
}

// std::vector<std::pair<int, int> > splitIntoPairs(const std::vector<int>& vector)
// {
// 	std::vector<std:pair<int, int> > pairs;
// 	for (size_t i = 0; i < vector.size(); i+= 2) {
// 			int first = std::min(vector[i], vector[i + 1]);
// 			int second = std::max(vector[i], vector[i + 1]);
// 			pairs.push_back(std::make_pair(first, second));
// 	}

// 	return pairs;
// }

// std::vectotr<int> extractHighestValues(const std::vector<std::pair<int, int> >& pairs)
// {
// 	std::vector<int> highestValues;
// 	for (size_t i = 0; i < pairs.size(); i++) {
// 		highestValues.push_back(pair.second);
// 	}

// 	return highestValues;
// }

// std::vector<int> recursiveSort(const std::vector<int>& vector) {
//     if (vector.size() <= 1) {
//         return vector;
//     }

//     std::vector<int> left(vector.begin(), vector.begin() + vector.size() / 2);
//     std::vector<int> right(vector.begin() + vector.size() / 2, vector.end());

//     left = recursiveSort(left);
//     right = recursiveSort(right);

//     std::vector<int> result;
//     std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
//     return result;
// }

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