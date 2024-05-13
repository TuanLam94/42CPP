
#include "PhoneBook.hpp"

int main() {
	int exit = 0;
	int	i = 0;
	std::string command;
	PhoneBook PhoneBook;

	PhoneBook.phonebookInit();
	while (exit == 0) {
	std::cout << "Enter command : ADD, SEARCH or EXIT\n";
	std::getline(std::cin, command);
	if (command == "ADD") {
		PhoneBook.addContact(i);
		i++;
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
