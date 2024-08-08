#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <limits.h>

bool 	errorHandling(char* input);
int		checkInput(char* input);
bool	isPositiveInt(char* token);

void	parseVectorList(char* input, std::vector<int>& vector, std::list<int>& list);

void	vectorSort(std::vector<int>& vector);
void	vectorMergeInsertSort(std::vector<int>& vector, int start, int end);

void	printVector(std::vector<int> vector);
void	printList(std::list<int> list);



#endif