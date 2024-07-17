#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

#define FLOAT_MAX 3.4028235677973366e+38;

template<typename T>
void parseMaps(std::string inputFile, std::string dataFile);

template<typename T>
std::map<std::string, T> parseFileToMap(std::string file, char delim);

template<typename T>
void printMap(std::multimap<std::string, T> map);

int whichDigitString(std::string str);
std::string substringBeforeDelimiter(std::string& str, char delim);
std::string substringAfterDelimiter(std::string& str, char delim);
std::string trim(std::string str);
double AbsDouble(double num);

#endif