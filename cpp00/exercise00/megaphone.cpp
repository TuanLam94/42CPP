#include <iostream>
#include <string>

int main(int argc, char **argv) {

int	i = 1;
int	j;
while (i < argc) {
	j = 0;
	while(argv[i][j] != '\0') {

		std::cout << (char)toupper(argv[i][j]);
		j++;
	}
	std::cout << " ";
	i++;
}
std::cout << std::endl;
return 0;
}
