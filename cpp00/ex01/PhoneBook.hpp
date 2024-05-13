#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class PhoneBook {
	private:
		Contact	contact[9];
	public:
		PhoneBook();
		~PhoneBook();
		int		contactnbr;
		void	phonebookInit(void);
		void	clearContact(int i);
		void	addContact(int i);
		void	searchContact(void);
};

#endif