#include <iostream>
#include <map>
#include <variant>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Wrong input, launch like this : ./btc input_file" << std::endl;
        return -1;
    }
    std::string inputFile = argv[1];
    std::string dataFile = "data.csv";

    using VariantType = std::variant<int, float>;

    std::map<std::string, VariantType> inputMap = parseInputFile(inputFile);
    std::map<std::string, VariantType> dataMap = parseDataFile(dataFile);

    return 0;
}
