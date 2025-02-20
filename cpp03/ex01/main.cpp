#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << "======= SCAVTRAP TESTS =========\n";

	ScavTrap Quinn("Quinn");
	ScavTrap Yass = Quinn;

	for (int i = 0; i < 11; i++) {
		Quinn.ScavTrap::attack("Gerald Darmanin");
	}
	
	std::cout << "Quinn guardgate : ";
	Quinn.guardGate();
	std::cout << std::endl;
	std::cout << "Yass guardgate : ";
	Yass.guardGate();
	std::cout << std::endl;

	Quinn.takeDamage(50);
	Quinn.beRepaired(10);
	Quinn.takeDamage(70);
	Quinn.beRepaired(10);

	return (0);
}