#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

#define FLOAT_MAX 3.4028235677973366e+38;

typedef std::multimap<std::string, std::string>::iterator MapIterator;

std::multimap<std::string, std::string> parseFileToMap(std::string& file, char delim);

void printMap(std::multimap<std::string, std::string>& map);

void bitcoinExchange(std::multimap<std::string, std::string>& inputMap, std::multimap<std::string, std::string>& dataMap);

void printDateError(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter);
bool isValidDate(const std::string& date);
bool wrongInputDate(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter);
void printResult(MapIterator& inputIter, MapIterator& dataIter);
int whichDigitString(std::string& str);
bool keyCheck(std::string& key);
std::string substringBeforeDelimiter(std::string& str, char delim);
std::string substringAfterDelimiter(std::string& str, char delim);
std::string trim(std::string str);
double AbsDouble(double num);


#endif