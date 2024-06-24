#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter &operator=(const ScalarConverter& other);

        static bool isLiteralInt(std::string str);
        static bool isLiteralFloat(std::string str);
        static bool isLiteralDouble(std::string str);
        static bool isLiteralChar(std::string str);

        static void printChar(int i);
        static void printInt(int i);
        static void printFloat(float i);
        static void printDouble(double i);
        static void printException(std::string str);
    public:
        ~ScalarConverter();
        
        static void convert(std::string str);
};

#endif