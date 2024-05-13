#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::phonebookInit(void)
{
	int i = 0;
	while (i < 9) {
		this->contact[i].index = -1;
		i++;
	}
	this->contactnbr = 0;
}

void PhoneBook::clearContact(int i)
{
	this->contact[i].firstName.clear();
	this->contact[i].lastName.clear();
	this->contact[i].nickname.clear();
	this->contact[i].number.clear();
	this->contact[i].secret.clear();
}

void PhoneBook::addContact(int i)
{
	if (i >= 8) {
		i = i % 8;
		PhoneBook::clearContact(i);
	}
	this->contact[i].index = i + 1;
	while (this->contact[i].firstName.empty()) {
		std::cout << "Contact first name ?\n";
		std::getline(std::cin, this->contact[i].firstName);
	}
	while (this->contact[i].lastName.empty()) {
		std::cout << "Contact last name ?\n";
		std::getline(std::cin, this->contact[i].lastName);
	}
	while (this->contact[i].nickname.empty()) {
		std::cout << "Contact nickname ?\n";
		std::getline(std::cin, this->contact[i].nickname);
	}
	while (this->contact[i].number.empty()) {
		std::cout << "Contact number ?\n";
		std::getline(std::cin, this->contact[i].number);
	}
	while (this->contact[i].secret.empty()) {
		std::cout << "Tell me then, what is their darkest secret ?\n";
		std::getline(std::cin, this->contact[i].secret);
	}
	this->contactnbr++;
	if (this->contactnbr > 8) {
		this->contactnbr = 8;
	}
}
void PhoneBook::searchContact(void)
{
	int	i = 0;
	std::string search;
	int searchIndex;

	while (this->contact[i].index != -1 && i < 8) {
		std::cout << std::right << std::setw(10) << this->contact[i].index;
		std::cout << "|";
		if (this->contact[i].firstName.length() > 10) {
			std::cout << std::right << std::setw(10) << this->contact[i].firstName.substr(0, 9) << ".";
		}
		else {
			std::cout << std::right << std::setw(10) << this->contact[i].firstName;
		}
		std::cout << "|";
		if (this->contact[i].lastName.length() > 10) {
			std::cout << std::right << std::setw(10) << this->contact[i].lastName.substr(0, 9) << ".";
		}
		else {
			std::cout << std::right << std::setw(10) << this->contact[i].lastName;
		}
		std::cout << "|";
		if (this->contact[i].nickname.length() > 10) {
			std::cout << std::right << std::setw(10) << this->contact[i].nickname.substr(0, 9) << ".";
		}
		else {
			std::cout << std::right << std::setw(10) << this->contact[i].nickname;
		}
		std::cout << "|\n";
		i++;
	}
	i = 0;
	if (this->contactnbr != 0) {
		std::cout << "Which contact to display ?\n";
		std::getline(std::cin, search);
		searchIndex = search[0] - '0';
		while (searchIndex < 1 || searchIndex > this->contactnbr || search.size() > 1) {
			std::cout << "Incorrect contact index, which contact to display ?\n";
			std::getline(std::cin, search);
			searchIndex = search[0] - '0';
		}
		std::cout << "index : " << this->contact[searchIndex - 1].index << std::endl;
		std::cout << "first name : " << this->contact[searchIndex - 1].firstName << std::endl;
		std::cout << "last name : " << this->contact[searchIndex - 1].lastName << std::endl;
		std::cout << "nickname : " << this->contact[searchIndex - 1].nickname << std::endl;
		std::cout << "number : " << this->contact[searchIndex - 1].number << std::endl;
		std::cout << "secret : " << this->contact[searchIndex - 1].secret << std::endl;
	}
	else {
		std::cout << "No contact in PhoneBook\n";
	}
}