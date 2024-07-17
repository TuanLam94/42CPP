#include <iostream>
#include <map>
#include <variant>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Wrong input, launch like this : ./btc input_file" << std::endl;
        return -1;
    }
    
    std::string inputFile(argv[1]);
    std::string dataFile = "data.csv";

    std::multimap<std::string, double> inputMap = parseFileToMap(inputFile, '|');
    std::multimap<std::string, double> dataMap = parseFileToMap(dataFile, ',');
    // std::cout << "===INPUT MAP===\n\n";
    // printMap(inputMap);
    // std::cout << "\n\n===DATA MAP===\n\n";
    // printMap(dataMap);

    bitcoinExchange(inputMap, dataMap);
    return 0;
}
