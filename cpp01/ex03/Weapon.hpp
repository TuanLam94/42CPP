#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class HumanB;
class HumanA;

class Weapon {
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string& getType(void);
		void setType(std::string type);
	private:
		std::string type;
};

#endif