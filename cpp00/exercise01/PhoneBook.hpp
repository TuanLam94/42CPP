#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

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