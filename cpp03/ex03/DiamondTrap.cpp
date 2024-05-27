#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 30;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_ad = FragTrap::_ad;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap string constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	*this = copy;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap& other)
{
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_ad = other._ad;
	}
	std::cout << "DiamondTrap assignment operator called\n";
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name : " << DiamondTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}