#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main ()
{
	std::cout << "====== CLAPTRAP TESTS ========\n" << std::endl;

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

	std::cout << std::endl;

	std::cout << "======= SCAVTRAP TESTS =========\n";

	std::cout << std::endl;

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

	std::cout << std::endl;

	std::cout << "======= FRAGTRAP TESTS =======\n";

	std::cout << std::endl;

	FragTrap JA("JA");
	FragTrap Matt = JA;

	for (int i = 0; i < 5; i++) {
		JA.attack("Depardieu");
	}

	std::cout << "JA highfives : ";
	JA.highFivesGuys();
	std::cout << std::endl;
	std::cout << "Matt highfives : ";
	Matt.highFivesGuys();
	std::cout << std::endl;

	JA.takeDamage(50);
	JA.beRepaired(10);
	JA.takeDamage(70);
	JA.beRepaired(10);

	std::cout << std::endl;

	std::cout << "======= DIAMONDTRAP TESTS ========\n";

	std::cout << std::endl;

	DiamondTrap Leon("Leon");

	std::cout << "---Assignment operator---\n";
	DiamondTrap Chatou = Leon;

	for (int i = 0; i < 5; i++) {
		Leon.FragTrap::attack("Hidalgo");
		Leon.DiamondTrap::attack("Hidalgus");
	}

	std::cout << "Who are you Leon ?\n";
	Leon.whoAmI();
	std::cout << std::endl;
	std::cout << "Who are you Chatou ?\n";
	Chatou.whoAmI();
	std::cout << std::endl;

	Leon.takeDamage(50);
	Leon.beRepaired(10);
	Leon.takeDamage(70);
	Leon.beRepaired(10);

	std::cout << "-------Checking if ClapTrap subobject is created only once-------\n";

	DiamondTrap Jackie;

	std::cout << "------Check end-----\n";

	return (0);
}