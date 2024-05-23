#include "ClapTrap.hpp"

int main ()
{
	ClapTrap Jones;
	ClapTrap John("John");

	John.takeDamage(5);
	John.beRepaired(1);

	ClapTrap Jack = John;

	for (int i = 0; i < 11; i++) {
		Jack.attack("Valerie Pecresse");
	}
	Jack.takeDamage(7);

	John.takeDamage(3);
	John.takeDamage(4);

	John.takeDamage(3);
	John.beRepaired(3);
	John.takeDamage(2);
	
	return (0);
}