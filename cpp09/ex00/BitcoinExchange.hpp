#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#include <limits>
#include <cerrno>
#include <climits>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>

#define FLOAT_MAX 3.4028235677973366e+38;

typedef std::multimap<std::string, std::string>::iterator MapIterator;


std::multimap<std::string, std::string> parseFileToMap(std::string& file, char delim);

void bitcoinExchange(std::multimap<std::string, std::string>& inputMap, std::multimap<std::string, std::string>& dataMap);

void printResult(MapIterator& inputIter, MapIterator& dataIter);
bool printErrors(const std::string& str);
int whichDigitString(std::string& str);
int checkLine(std::string line, char delim);
bool isValidDate(const std::string& date);
void printMap(std::multimap<std::string, std::string>& map);
std::string substringBeforeDelimiter(std::string& str, char delim);
std::string substringAfterDelimiter(std::string& str, char delim);
std::string trim(std::string str);


// void printDateError(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter);
// bool wrongInputDate(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter);
// bool keyCheck(std::string& key);
// double AbsDouble(double num);


#endif

// void printResult(MapIterator& inputIter, MapIterator& dataIter)
// {
// 	size_t pos = inputIter->first.find(" ");
// 	std::string tempKey = inputIter->first.substr(pos + 1);

// 	if (printErrors(inputIter->second))
// 		return ;

//     else if (whichDigitString(dataIter->second) == 0 && whichDigitString(inputIter->second) == 0) {				//is int
//         long long dataInt = std::strtoll(dataIter->second.c_str(), NULL, 10);
//         long long inputInt = std::strtoll(inputIter->second.c_str(), NULL, 10);
//         long long res = dataInt * inputInt;

// 		std::cout << tempKey;
//         if (res > INT_MAX)
//             std::cout << " Error: too large a number.\n";
// 		else
// 			std::cout << " => " << inputIter->second << " => " << res << std::endl;
//     }

//     else {																									//is float
//         double dataDouble = std::strtod(dataIter->second.c_str(), NULL);
//         double inputDouble = std::strtod(inputIter->second.c_str(), NULL);
//         double res = dataDouble * inputDouble;

// 		std::cout << tempKey;
//         if (res > INT_MAX)
//             std::cout << " Error: too large a number.\n";
//         else if (whichDigitString(inputIter->second) == -1)
//             std::cout << " " << inputIter->second << std::endl;
// 		else
// 			std::cout << " => " << inputIter->second << " => " << res << std::endl;
//     }
// }