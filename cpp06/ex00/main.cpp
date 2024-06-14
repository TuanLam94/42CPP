#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Launch like this : ./convert string\n";
        return 1;
    }
    ScalarConverter* converter;

    converter->convert(argv[1]);
    
    return 0;
}