#include "RPN.hpp"

std::deque<std::string> parseToDeque(char* input)
{
    std::deque<std::string> deque;

    char* token = std::strtok(input, " ");
    while (token != NULL) {
        deque.push_back(std::string(token));
        token = std::strtok(NULL, " ");
    }
    return deque;
}

int checkDeque(std::deque<std::string> deque)
{
    int count = 0;

    for (std::deque<std::string>::iterator it = deque.begin(); it != deque.end(); it++) {
        if (std::strtoll(it->c_str(), NULL, 10) > 10)
            return 0;
    }

    std::deque<std::string>::iterator it = deque.begin();
    if (it == deque.end() || !isStringDigit(*it))
        return 0;
    it++;

    while (it != deque.end()) {
        while (it != deque.end() && isStringDigit(*it)) {
            it++;
            count++;
        }
        while (it != deque.end() && isStringToken(*it)) {
            it++;
            count--;
        }

        if (count != 0)
            return 0;
    }
    return count == 0 ? 1 : 0;
}

bool isStringDigit(std::string str)
{
    if (str.size() > 2 || str.empty() || (str.size() == 2 && str[0] != '-') || (str.size() == 1 && !isdigit(str[0])))
        return false;
    return true;
}

bool isStringToken(std::string str)
{
    return (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
}

void printDeque(std::deque<std::string> deque)
{
    std::cout << "\n===DEQUE : ===\n";

    for (std::deque<std::string>::iterator it = deque.begin(); it != deque.end(); *it++) {
        std::cout << "token = " << *it << std::endl;
    }
}