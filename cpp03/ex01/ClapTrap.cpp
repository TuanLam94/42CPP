#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) 
{
	std::cout << "String constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "Copy Constructor called\n";
}

ClapTrap &ClapTrap::operator = (const ClapTrap& other)
{
	std::cout << "Assignment operator called\n";
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_ad = other._ad;
	}
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0) {
		std::cout << "ClapTrap " << _name << " has been destroyed ! They can't attack !\n";
		return ;
	}
	if (_ep >= 1) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " point(s) of damage !\n";
		_ep--;
	}
	else
		std::cout << "Not enough energy points !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0) {
		std::cout << "ClapTrap " << _name << " has been destroyed ! They can't take any more damage !\n";
		return ;
	}
	_hp -= amount;
	if (_hp > 0)
		std::cout << "ClapTrap " << _name << " takes " << amount << " point(s) of damage !\n";
	else
		std::cout << "ClapTrap " << _name << " takes " << amount << " point(s) of damage. " << _name << " has been destroyed !\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0) {
		std::cout << "ClapTrap " << _name << " has been destroyed ! They can't be repaired !\n";
		return ;
	}
	if (_ep >= 1) {
		_hp += amount;
		std::cout << "ClapTrap " << _name << " repairs themselves for " << amount << " hit points !\n";
		_ep--;
	}
	else
		std::cout << "Not enough energy points !\n";
}