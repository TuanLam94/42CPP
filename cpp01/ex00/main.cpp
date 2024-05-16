#include "Zombie.hpp"

int main()
{
	Zombie* zombieOne = Zombie::newZombie("One");
	zombieOne->announce();

	Zombie::randomChump("Two");

	delete zombieOne;
	return (0);
}