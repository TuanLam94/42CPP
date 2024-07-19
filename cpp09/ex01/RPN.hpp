#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>

std::deque<std::string> parseToDeque(char* input);
int checkDeque(std::deque<std::string> deque);
bool isStringDigit(std::string str);
bool isStringToken(std::string str);



void printDeque(std::deque<std::string> deque);



#endif