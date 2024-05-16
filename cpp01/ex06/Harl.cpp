#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
	info();
}

void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	warning();
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	error();
}

void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	if (level.empty()) {
		std::cerr << "no level input\n";
		return ;
	}
	
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	switch(i) {
		case 0:
			debug();
			break;
		case 1:
			info();
			break;
		case 2:
			warning();
			break;
		case 3:
			error();
			break;
	}
}
