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

	int i = 10000;
	char buffer[2048];

    std::getline(in, line);

    while (std::getline(in, line)) {
        std::string key;
        std::string value;

		key = trim(substringBeforeDelimiter(line, delim));

		if (delim == '|') {
			std::sprintf(buffer, "%d ", i);
			std::string temp(buffer);
			key = temp + key;

			int toParse = checkLine(line, delim);
            switch (toParse) {
                case -1:
                    value = "Error: wrong format.";
                    break;
                case -2:
                    value = "Error: invalid date.";
                    break;
                case -3:
                    value = "Error: not a positive number.";
                    break;
                case -4:
                    value = "Error: too large a number.";
                    break;
                case -5:
                    value = "Error: No data for this date, data start at 2009-01-02.";
                    break;
                default:
                    value = trim(substringAfterDelimiter(line, delim));
                    break;
            }
		}
		else
			value = trim(substringAfterDelimiter(line, delim));
		i++;
        map.insert(std::pair<std::string, std::string>(key, value));
    }
    return map;
}

int checkLine(std::string line, char delim)
{
	int dotCount = 0;
	int delimCount = 0;
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

	std::string valueLine = trim(line.substr(delimPos + 1, line.size() - (delimPos + 1)));
	if (std::strtod(valueLine.c_str(), NULL) < 0)
		return -3;							//negative Number;

	if (std::strtod(valueLine.c_str(), NULL) > 1000)
		return -4;							//too big a number;

	if (dateLine < "2009-01-02")
		return -5;
	return 0;
}

bool isValidDate(const std::string& date)
{
    int month, day;

    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || month > 12 || day > 31)
        return false;
	
    return true;
}

void bitcoinExchange(std::multimap<std::string, std::string>& inputMap, std::multimap<std::string, std::string>& dataMap)
{
    MapIterator inputIter = inputMap.begin();
    MapIterator dataIter = dataMap.begin();

	// std::cout << "Input Map : \n";
	// printMap(inputMap);
	// std::cout << "Data Map : \n";
	// printMap(dataMap);

	// (void)inputIter;
	// (void)dataIter;

    while (inputIter != inputMap.end()) {                    
		size_t pos = inputIter->first.find(" ");
		std::string tempKey = inputIter->first.substr(pos + 1);                           
        dataIter = dataMap.upper_bound(tempKey);
            if (dataIter != dataMap.begin())
                dataIter--;
            printResult(inputIter, dataIter);
        inputIter++;
    }
}

void printResult(MapIterator& inputIter, MapIterator& dataIter)
{
	size_t pos = inputIter->first.find(" ");
	std::string tempKey = inputIter->first.substr(pos + 1);

	if (printErrors(inputIter->second))
		return ;

    else if (whichDigitString(dataIter->second) == 0 && whichDigitString(inputIter->second) == 0) {				//is int
        long long dataInt = std::strtoll(dataIter->second.c_str(), NULL, 10);
        long long inputInt = std::strtoll(inputIter->second.c_str(), NULL, 10);
        long long res = dataInt * inputInt;

		std::cout << tempKey;
        if (res > INT_MAX)
            std::cout << " Error: too large a number.\n";
		else
			std::cout << " => " << inputIter->second << " => " << res << std::endl;
    }

    else {																									//is float
        double dataDouble = std::strtod(dataIter->second.c_str(), NULL);
        double inputDouble = std::strtod(inputIter->second.c_str(), NULL);
        double res = dataDouble * inputDouble;

		std::cout << tempKey;
        if (res > INT_MAX)
            std::cout << " Error: too large a number.\n";
        else if (whichDigitString(inputIter->second) == -1)
            std::cout << " " << inputIter->second << std::endl;
		else
			std::cout << " => " << inputIter->second << " => " << res << std::endl;
    }
}

bool printErrors(const std::string& str)
{
	if (str.find("data") != std::string::npos) {
		std::cout << "Error: No data for this date, data start at 2009-01-02." << std::endl;
		return true;
	}
	else if (str.find("format") != std::string::npos) {
		std::cout << "Error: wrong format." << std::endl;
		return true;
	}
	else if (str.find("date") != std::string::npos) {
		std::cout << "Error: invalid date." << std::endl;
		return true;
	}
	else if (str.find("positive") != std::string::npos) {
		std::cout << "Error: not a positive number." << std::endl;
		return true;
	}
	else if (str.find("large") != std::string::npos) {
		std::cout << "Error: too large a number." << std::endl;
		return true;
	}
	else
		return false;
}

int whichDigitString(std::string& str)
{
    if (str.empty())
		return -1;

	for (size_t i = 0; i < str.size(); i++) {
		if (!isdigit(str[i]) && str[i] != '.')
			return -1;
	}

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

// double AbsDouble(double num)
// {
//     if (num < 0)
//         return -num;
//     return num;
// }

// bool keyCheck(std::string& key)
// {
//     for (int i = 0; i < 4; i++) {
//         if (!isdigit(key[i]))
//             return false;
//     }
//     if (key[4] != '-' && key[7] != '-')
//         return false;

//     char *endptr;

//     std::string month = key.substr(5, 2);
//     for (int i = 0; i < 2; i++) {
//         if (!isdigit(month[i]))
//             return false;
//     }
//     if (strtoll(month.c_str(), &endptr, 10) > 12)
//         return false;
    
//     std::string day = key.substr(8, 2);
//     for (int i = 0; i < 2; i++) {
//         if (!isdigit(day[i])) {
//             return false;
//         }
//     }
//     if (strtoll(month.c_str(), &endptr, 10) > 31)
//         return false;

//     return true;
// }

// void printDateError(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter)
// {
//     MapIterator dataIter = dataMap.begin();

//     if (!isValidDate(inputIter->first)) {
//         std::cout << inputIter->first << ": Invalid date\n";
//     }
//     else {
//         size_t pos = inputIter->first.find(" ");
//         std::cout << inputIter->first.substr(0, pos) << " No data for this date, data start at " << dataIter->first << std::endl;
//     }
// }

// bool wrongInputDate(std::multimap<std::string, std::string>& dataMap, MapIterator& inputIter)
// {
//     MapIterator dataIter = dataMap.begin();

//     while (dataIter != dataMap.end()) {
//         if (dataIter->first <= inputIter->first)
//             return false;
//         dataIter++;
//     }
//     return true;
// }
