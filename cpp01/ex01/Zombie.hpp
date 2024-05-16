#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie ();
    	Zombie (std::string name);
		~Zombie();
		void announce(void);
		static Zombie* newZombie(std::string name);
		static void randomChump(std::string name);
		static Zombie* zombieHorde(int n, std::string name);
	private:
		std::string name;
};

#endif