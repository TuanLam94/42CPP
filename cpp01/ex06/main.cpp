#include "Harl.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cerr << "Args error, launch like this : ./harlFilter LEVEL\n", 1);
	Harl harl;
	std::string level = argv[1];

	harl.complain(level);

	return (0);
}