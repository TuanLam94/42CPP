#include <iostream>
#include <map>
#include <variant>

template<typename T>
int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Wrong input, launch like this : ./btc input_file" << std::endl;
        return -1;
    }
    std::string inputFile = argv[1];
    std::string dataFile = "data.csv";

    parseMaps(inputFile, dataFile);

    // std::map<std::string, T> inputMap = parseInputFile(inputFile);
    // std::map<std::string, T> dataMap = parseDataFile(dataFile);

    (void)inputFile;
    (void)dataFile;
    (void)inputMap;
    (void)dataMap;

    return 0;
}
