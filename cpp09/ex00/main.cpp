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
    parseMaps(inputFile, dataFile);

    return 0;
}
