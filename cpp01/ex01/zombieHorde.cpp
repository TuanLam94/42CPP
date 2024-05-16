#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int n, std::string name)
{
	Zombie* zombieHorde = new Zombie[n];

	for (int i = 0; i < n; i++) {
		zombieHorde[i].name = name;
	}

	return zombieHorde;
}