#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

#define FLOAT_MAX 3.4028235677973366e+38;

void parseMaps(std::string inputFile, std::string dataFile);

std::multimap<std::string, double> parseFileToMap(std::string file, char delim);

void printMap(std::multimap<std::string, double> map);

int whichDigitString(std::string str);
std::string substringBeforeDelimiter(std::string& str, char delim);
std::string substringAfterDelimiter(std::string& str, char delim);
std::string trim(std::string str);
double AbsDouble(double num);

#endif