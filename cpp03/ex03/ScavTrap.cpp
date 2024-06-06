#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 30;
	std::cout << "ScavTrap string constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator = (const ScavTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_ad = other._ad;
	}
	std::cout << "ScavTrap assignment operator called\n";
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp <= 0) {
		std::cout << "ScavTrap " << _name << " has been destroyed ! They can't attack !\n";
		return ;
	}
	if (_ep >= 1) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ad << " point(s) of damage !\n";
		_ep--;
	}
	else
		std::cout << "Not enough energy points !\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode\n";
}