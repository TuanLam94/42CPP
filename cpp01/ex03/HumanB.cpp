#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << "attacks with their bear fists. Ouch !" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}