#include "Zombie.hpp"

int main ()
{
	Zombie* horde = Zombie::zombieHorde(5, "Nemo");

	for (int i = 0; i < 5; ++i) {
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}