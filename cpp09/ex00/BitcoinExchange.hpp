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

#endif
