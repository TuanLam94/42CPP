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
		std::cout << "no function\n";
		return ;
	}

	std::string	tab[4] = {"debug", "info", "warning", "error"};
 	FunctionPtr ftab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (tab[i] == level) {
			(this->*ftab[i])();
			return ;
		}
	}
	std::cout << "no function"<< std::endl;
}
