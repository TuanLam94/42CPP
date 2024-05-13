#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact {
	public:
    	Contact();
		~Contact();
		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string secret;
};

#endif