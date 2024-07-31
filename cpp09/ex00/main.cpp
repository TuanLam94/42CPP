#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Wrong input, launch like this : ./btc input_file" << std::endl;
        return -1;
    }

    //bien comparer output avant de push

    std::string inputFile(argv[1]);
    std::string dataFile = "data.csv";
    std::multimap<std::string, std::string> inputMap = parseFileToMap(inputFile, '|');
    std::multimap<std::string, std::string> dataMap = parseFileToMap(dataFile, ',');

    bitcoinExchange(inputMap, dataMap);

    return 0;
}
