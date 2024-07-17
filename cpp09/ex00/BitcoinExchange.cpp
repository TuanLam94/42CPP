#include <iostream>

template<typename T>
void parseMaps(std::string inputFile, std::string dataFile)
{
    std::map<std::string, T> inputMap = parseFileToMap(inputFile, "|");
    std::map<std::string, T> dataMap = parseFileToMap(dataFile, ",");
}