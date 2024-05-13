#include <iostream>
#include <string>

std::string trim(std::string str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start])) {
		start++;
	}
	while (end > start && std::isspace(str[end - 1])) {
		end--;
	}

	return (str.substr(start, end - start));
}

int main(int argc, char **argv) 
{
	int	i = 1;
	int	j;
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (i < argc) {
		std::string arg = trim(argv[i]);
		j = 0;
		while (arg[j] != '\0') {
			std::cout << (char)toupper(arg[j]);
			j++;
		}
		j = 0;
		if (arg[j] != '\0') {
			std::cout << " ";
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
