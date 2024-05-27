#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int	_hp;
		int	_ep;
		int	_ad; 
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator = (const ClapTrap& other);
		~ClapTrap();
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif