#include "BitcoinExchange.hpp"

typedef std::multimap<std::string, std::string>::iterator MapIterator;

std::multimap<std::string, std::string> parseFileToMap(std::string& file, char delim)
{
    std::ifstream in(file.c_str());
    if (!in.is_open()) {
        std::cerr << "Could not open the file " << file << ".\nExiting..." << std::endl;
        exit(-1);
    }

    std::multimap<std::string, std::string> map;
    std::string line;

    std::getline(in, line);

    while (std::getline(in, line)) {
        std::string key;
        std::string value;

		//checkline

        key = substringBeforeDelimiter(line, delim);
        value = substringAfterDelimiter(line, delim);

        if (key == line)
            key = key + " Error: wrong input";
        else if (trim(value).empty())
            key = key + "Error: no value found";

        key = trim(key);
        value = trim(value);

        if (!keyCheck(key))
            map.insert(std::pair<std::string, std::string>(key, ""));
        else if (whichDigitString(value) == -1)
            map.insert(std::pair<std::string, std::string>(key, value));
        else
            map.insert(std::pair<std::string, std::string>(key, value));
    }
    return map;
}

int whichDigitString(std::string& str)
{
    int count = 0;

    if (str.empty())
        return -2;

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
    if (errno == 0 && *endptr == '\0' && doubleValue >= INT_MIN && doubleValue <= INT_MAX)
        return 1;                                                                   //is float

    return -1;
}

void bitcoinExchange(std::multimap<std::string, std::string>& inputMap, std::multimap<std::string, std::string>& dataMap)
{
    MapIterator inputIter = inputMap.begin();
    MapIterator dataIter = dataMap.begin();
    size_t i = 0;

    // std::cout << "===INPUT MAP===\n\n";
    // printMap(inputMap);
    // std::cout << "\n\n===DATA MAP===\n\n";
    // printMap(dataMap);

    // (void)inputIter;
    // (void)dataIter;
    // (void)i;

    while (inputIter != inputMap.end() && i < inputMap.size()) {
        if (wrongInputDate(dataMap, inputIter))
            printDateError(dataMap, inputIter);
        else {
            while (dataIter != dataMap.end() && dataIter->first <= inputIter->first)
                dataIter++;
            if (dataIter != dataMap.begin())
                dataIter--;
            printResult(inputIter, dataIter);
        }
        i++;
        inputIter++;
    }
}

void printDateError(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter)
{
    MapIterator dataIter = dataMap.begin();

    if (!isValidDate(inputIter->first)) {
        std::cout << inputIter->first << ": Invalid date\n";
    }
    else {
        size_t pos = inputIter->first.find(" ");
        std::cout << inputIter->first.substr(0, pos) << " No data for this date, data start at " << dataIter->first << std::endl;
    }
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int month, day;

    month = std::atoi(date.substr(5, 2).c_str());
    if (month > 12)
        return false;
    
    day = std::atoi(date.substr(8, 2).c_str());
    if (day > 31)
        return false;

    return true;
}

int checkLine(std::string line, char delim)
{
	int dotCount = 0;
	int delimCount = 0;
	size_t dotPos = line.find('.');
	size_t delimPos = line.find(delim);

	for (size_t i = 0; i < line.size(); i++) {
		if (line[i] == '.')
			dotCount++;
		if (line[i] == delim)
			delimCount++;
	}
	if (dotCount > 1 || delimCount != 1)
		return -1;							//wrong Format;

	std::string dateLine = trim(line.substr(0, delimPos));
	if (!isValidDate(dateLine))
		return -2;							//wrong Date;

	std::string valueLine = trim(line.substr(delimPos + 1, std::npos))
	if (std::strtod(valueLine.c_str()) < 0)
		return -3;							//negative Number;

	if (std::strtod(valueLine.c_str()) > 1000)
		return -4;							//too big a number;

	
}

bool wrongInputDate(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter)
{
    MapIterator dataIter = dataMap.begin();

    while (dataIter != dataMap.end()) {
        if (dataIter->first <= inputIter->first)
            return false;
        dataIter++;
    }
    return true;
}

void printResult(MapIterator& inputIter, MapIterator& dataIter)
{
    if (inputIter->second.empty())
        std::cout << inputIter->first << std::endl;

    else if (whichDigitString(dataIter->second) == 0 && whichDigitString(inputIter->second) == 0) {
        
        long long dataInt = std::strtoll(dataIter->second.c_str(), NULL, 10);
        long long inputInt = std::strtoll(inputIter->second.c_str(), NULL, 10);
        long long res = dataInt * inputInt;
        if (inputInt > 1000)
            std::cout << inputIter->first << " => input value is too big, max is 1000" << std::endl;
        else if (res > INT_MAX)
            std::cout << inputIter->first << " Error: too large a number\n";
        else if (res < 0)
            std::cout << inputIter->first<< " Error: not a positive number\n";
        else
            std::cout << inputIter->first << " => " << res << std::endl;
    }

    else if (whichDigitString(dataIter->second) == 1 || whichDigitString(inputIter->second) == 1) {
        double dataDouble = std::strtod(dataIter->second.c_str(), NULL);
        double inputDouble = std::strtod(inputIter->second.c_str(), NULL);
        double res = dataDouble * inputDouble;

        if (inputDouble > 1000)
            std::cout << inputIter->first << " => input value is too big, max is 1000" << std::endl;
        else if (res < 0)
            std::cout << inputIter->first << " Error: not a positive number\n";
        else if (res > INT_MAX)
            std::cout << inputIter->first << " Error: too large a number\n";
        else
            std::cout << inputIter->first << " => " << res << std::endl;
    }
    else
        std::cout << inputIter->first << " => " << inputIter->second << std::endl;
}

void printMap(std::multimap<std::string, std::string>& map)
{
    for (MapIterator iter = map.begin(); iter != map.end(); iter++) {
        std::cout << "key: " << iter->first << " value: " << iter->second << std::endl;
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

bool keyCheck(std::string& key)
{
    for (int i = 0; i < 4; i++) {
        if (!isdigit(key[i]))
            return false;
    }
    if (key[4] != '-' && key[7] != '-')
        return false;

    char *endptr;

    std::string month = key.substr(5, 2);
    for (int i = 0; i < 2; i++) {
        if (!isdigit(month[i]))
            return false;
    }
    if (strtoll(month.c_str(), &endptr, 10) > 12)
        return false;
    
    std::string day = key.substr(8, 2);
    for (int i = 0; i < 2; i++) {
        if (!isdigit(day[i])) {
            return false;
        }
    }
    if (strtoll(month.c_str(), &endptr, 10) > 31)
        return false;

    return true;
}
