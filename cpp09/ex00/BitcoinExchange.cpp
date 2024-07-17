#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#include <limits>
#include <cerrno>
#include <climits>
#include <fstream>
#include <cstdlib>
#include <iterator>

void parseMaps(std::string inputFile, std::string dataFile)
{
    std::multimap<std::string, double> inputMap = parseFileToMap(inputFile, '|');
    std::multimap<std::string, double> dataMap = parseFileToMap(dataFile, ',');

    printMap(inputMap);
    printMap(dataMap);
}

std::multimap<std::string, double> parseFileToMap(std::string file, char delim)
{
    std::ifstream in(file.c_str());
    if (!in.is_open()) {
        std::cerr << "Could not open the file " << file << ".\nExiting..." << std::endl;
        exit(-1);
    }

    std::multimap<std::string, double> map;
    std::string line;

    while (std::getline(in, line)) {
        std::string key;
        std::string value;

        key = trim(substringBeforeDelimiter(line, delim));
        value = trim(substringAfterDelimiter(line, delim));       //first check wrong input

        char *endptr;
        double doubleValue = strtod(value.c_str(), &endptr);
        map.insert(std::pair<std::string, float>(key, doubleValue));
    }
    return map;
}

int whichDigitString(std::string str)
{
    int count = 0;

    if (str.empty())
        return -1;

    for (unsigned long i = 0; i < str.size(); i++) {
        if (str[i] == '.')
            count++;
        if (!isdigit(str[i]) && str[i] != '.')
            return -1;
    }
    if (count > 1)
        return -1;                                                                  //wrong input
                            
    errno = 0;                                                                      
    char *endptr;
    long long longValue = std::strtoll(str.c_str(), &endptr, 10);
    if (errno == 0 && *endptr == '\0' && longValue >= INT_MIN && longValue <= INT_MAX)
        return 0;                                                                   //is int

    errno = 0;
    double doubleValue = std::strtod(str.c_str(), &endptr);
    if (errno == 0 && *endptr == '\0' && AbsDouble(doubleValue) < 3.4028235677973366e+38)
        return 1;                                                                   //is float

    return -1;
}

void printMap(std::multimap<std::string, double> map)
{
    typedef std::multimap<std::string, double>::iterator MapIterator;

    for (MapIterator iter = map.begin(); iter != map.end(); iter++) {
        std::cout << iter->first << ": " << iter->second << std::endl;
    }
}

std::string substringBeforeDelimiter(std::string& str, char delim)
{
    size_t pos = str.find(delim);

    if (pos != std::string::npos)
        return str.substr(0, pos);
    return str;
}

std::string substringAfterDelimiter(std::string& str, char delim)
{
    size_t pos = str.find(delim);

    if (pos != std::string::npos)
        return str.substr(pos + 1);
    return str;
}

std::string trim(std::string str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start])) {
		start++;
	}
	while (end > start && std::isspace(str[end - 1])) {
		end--;
	}

	return (str.substr(start, end - start));
}

double AbsDouble(double num)
{
    if (num < 0)
        return -num;
    return num;
}


        // switch (whichDigitString(value)) {
        //     case -1:
        //     {
        //         key = "wrong input";
        //         map.insert(std::pair<std::string, int>(key, strtol(value.c_str(), &endptr, 10)));
        //         break;
        //     }
        //     case 0:
        //     {
        //         int intValue = strtol(value.c_str(), &endptr, 10);
        //         map.insert(std::pair<std::string, int>(key, intValue));
        //         break;
        //     }
        //     case 1:
        //     {
        //         float floatValue = strtod(value.c_str(), &endptr);
        //         map.insert(std::pair<std::string, float>(key, floatValue));
        //         break;
        //     }
        // }