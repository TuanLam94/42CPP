#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack(void);
	private:
		std::string name;
		Weapon& weapon;
};

#endif