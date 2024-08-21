#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <climits>

std::deque<std::string> parseToDeque(char* input);
int checkDeque(std::deque<std::string> deque);
bool isStringDigit(std::string str);
bool isStringOperator(std::string str);
bool willOverflow(int num1, int num2);
void operate(std::deque<int>& numq, std::deque<char>& opq);
void RPN(std::deque<std::string> deque);

void printDeque(std::deque<std::string> deque);
void printDequeInt(std::deque<int> deque);

#endif