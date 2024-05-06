#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact {
	public:
		int			index = -1;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string secret;
};

class PhoneBook {
	private:
	Contact	contact[8];
	public:
	int		contactnbr = 0;
	void	addContact(int i);
	void	searchContact(void);
};


void PhoneBook::addContact(int i)
{
	this->contact[i].index = i;
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
	char search;
	int searchIndex;

	while (this->contact[i].index != -1) {
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
		std::cin >> search;
		searchIndex = search - '0';
		while (searchIndex < 0 || searchIndex > this->contactnbr) {
			std::cout << "Incorrect contact index, which contact to display ?\n";
			std::cin >> search;
			searchIndex = search - '0';
		}
		std::cout << "index : " << this->contact[searchIndex].index << std::endl;
		std::cout << "first name : " << this->contact[searchIndex].firstName << std::endl;
		std::cout << "last name : " << this->contact[searchIndex].lastName << std::endl;
		std::cout << "nickname : " << this->contact[searchIndex].nickname << std::endl;
		std::cout << "number : " << this->contact[searchIndex].number << std::endl;
		std::cout << "secret : " << this->contact[searchIndex].secret << std::endl;
	}
	else {
		std::cout << "No contact in contact list\n";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
	int exit = 0;
	int	i = 0;
	std::string command;
	PhoneBook PhoneBook;

	while (exit == 0) {
	std::cout << "Enter command : ADD, SEARCH or EXIT\n";
	std::getline(std::cin, command);
	if (command == "ADD") {
		PhoneBook.addContact(i);
		i++;
		if (i == 8) {
			i = 1;
		}
	}
	else if (command == "SEARCH") {
		PhoneBook.searchContact();
	}
	else if (command == "EXIT") {
		exit = 1;
	}
	else {
		std::cout << "Wrong command, possible commands are ADD, SEARCH or EXIT\n";
	}
	command.clear();
	}
	return (0);
}