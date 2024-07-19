#include "RPN.hpp"

// peut etre fait differemment. Creer une deque (ou stack). 
// Tant qu'on trouve des nombres, les ajouter a la stack, puis appliquer le / les tokens'
// puis les retirer de la stack, et ajouter le resultat until end;


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Invalid number of arguments, RPN only takes a string as input.\nLaunch like this : ./RPN \"X Y + Z * W -...\"" << std::endl;
        return -1;
    }

    std::deque<std::string> deque = parseToDeque(argv[1]);

    printDeque(deque);

    if (!checkDeque(deque)) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }
    else
        std::cout << "valid input" << std::endl;

    


    // if (!checkInput(deque)) {
    //     std::cout << "Error: wrong input format\n";
    //     return -1;
    // }

    // RPN(deque);

    return 0;
}