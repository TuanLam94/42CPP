#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isLiteralInt(std::string str)
{
    std::string::const_iterator it = str.begin();
    if (str.c_str()[0] == '-')
        it++;
    while (it != str.end() && isdigit(*it))
        it++;
    return (!str.empty() && it == str.end());
}

bool ScalarConverter::isLiteralFloat(std::string str)
{
    int len = str.length();
    if (len > 1 && str[len - 1] == 'f')
        return (str.find('.') != std::string::npos);
    return false;
}

bool ScalarConverter::isLiteralDouble(std::string str)
{
    int count = 0;
    int len = str.length();

    if (len <= 1 || str.find('.') == std::string::npos)
        return false;
    for (int i = 0; i < len; i++) {
        if (str.c_str()[i] == '.')
            count++;
        if ((!isdigit(str[i]) && str[i] != '.' && (str[i] != '-' || i != 0)) || count > 1)
            return false;
    }
    return count == 1;
}

bool ScalarConverter::isLiteralChar(std::string str)
{
    return (str.length() == 1 /*&& str.c_str()[0] >= 0 && str.c_str()[0] <= 255*/);
}

void ScalarConverter::printChar(int i)
{
    if (i >= 0 && i <= 255) {
        if (isprint(i)) {
            std::cout << "char : " << static_cast<char>(i) << std::endl;
        }
        else
            std::cout << "Non displayable\n";
    }
    else
        std::cout << "char: Impossible" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    if (i < -2147483647)
        std::cout << "int : is a bit low my friend\n";
    else if (i > 2147483647)
        std::cout << "int : is a bit high dude\n";
    else
        std::cout << "int : " << i << std::endl;
}

void ScalarConverter::printFloat(float i)
{
    std::cout << "float : " << i << "f" << std::endl;
}

void ScalarConverter::printDouble(double i)
{
    std::cout << "double : " << i << std::endl;
}

void ScalarConverter::printException(std::string str)
{
    if (str == "-inff" || str == "-inf") {
        std::cout << "char : Impossible\n";
        std::cout << "int : -inf\n";
        std::cout << "float : -inff\n";
        std::cout << "double : -inf\n";
    }
    else if (str == "inff" || str == "inf") {
        std::cout << "char : Impossible\n";
        std::cout << "int : +inf\n";
        std::cout << "float : +inff\n";
        std::cout << "double : +inf\n";
    }
    else if (str == "nan") {
        std::cout << "char : Impossible\n";
        std::cout << "int : Impossible\n";
        std::cout << "float : Impossible\n";
        std::cout << "double : Impossible\nIt's not a number, dummy !" << std::endl;
    }
    else
        std::cout << "Wrong input\n";
}

void ScalarConverter::convert(std::string str)
{
    if (isLiteralInt(str)) {
        int intValue = atoi(str.c_str());
        printChar(intValue);
        printInt(intValue);
        printFloat(intValue);
        printDouble(intValue);
    }
    else if (isLiteralFloat(str)) {
        float floatValue = atof(str.c_str());
        printChar((floatValue));                                      //no need to cast here
        printInt(static_cast<int>(floatValue));
        printFloat(static_cast<float>(floatValue));
        printDouble((floatValue));
    }
    else if (isLiteralDouble(str)) {
        double doubleValue = atof(str.c_str());
        printChar((doubleValue));
        printInt(static_cast<int>(doubleValue));
        printFloat(static_cast<float>(doubleValue));
        printDouble((doubleValue));
    }
    else if (isLiteralChar(str)) {
        std::cout << "char : " << str.c_str()[0] << std::endl;
        std::cout << "int : Impossible" << std::endl;
        std::cout << "float : Impossible" << std::endl;
        std::cout << "double : Impossible" << std::endl;
    }
    else
        printException(str);
}