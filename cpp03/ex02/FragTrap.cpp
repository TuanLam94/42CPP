#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap string constructor called\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator = (const FragTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_ad = other._ad;
	}
	std::cout << "FragTrap assignment operator called\n";
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap destructor called\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << _name << " asks for a high five fellows !\n";
}