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
        while (it != deque.end() && isStringOperator(*it)) {
            it++;
            count--;
        }
    }
	
    return count == 0 ? 1 : 0;
}

void RPN(std::deque<std::string> deque)
{
	std::deque<int> numDeque;
	std::deque<char> opDeque;
	std::deque<std::string>::iterator it = deque.begin();

	while (it != deque.end()) {
		while (isStringDigit(*it)) {
			numDeque.push_back(strtoll(it->c_str(), NULL, 10));
			it++;
		}
		while (isStringOperator(*it)){
			opDeque.push_front(it->at(0));
			it++;
		}

		operate(numDeque, opDeque);
	}

	std::cout << numDeque.back() << std::endl;
}

void operate(std::deque<int>& numq, std::deque<char>& opq)
{
	while (numq.size() > 1 && !opq.empty()) {
		int num1 = numq.back();
		numq.pop_back();
		int num2 = numq.back();
		numq.pop_back();
		
		char op = opq.back();
		opq.pop_back();

		int res;
		switch(op) {
			case '+':
				res = num2 + num1;
				break;
			case '-':
				res = num2 - num1;
				break;
			case '*':
				res = num2 * num1;
				break;
			case '/':
				res = num2 / num1;
				break;
		}
		numq.push_back(res);
	}
}

bool isStringDigit(std::string str)
{
    if (str.size() > 2 || str.empty() || (str.size() == 2 && str[0] != '-') || (str.size() == 1 && !isdigit(str[0])))
        return false;
    return true;
}

bool isStringOperator(std::string str)
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

void printDequeInt(std::deque<int> deque)
{
    std::cout << "\n===DEQUE : ===\n";

    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); *it++) {
        std::cout << "token = " << *it << std::endl;
    }
}