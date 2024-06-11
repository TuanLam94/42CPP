#include "Bureaucrat.hpp"

int main()
{
    std::cout << "====TESTS BEGIN====\n\n";
    
    try
    {
        Bureaucrat Antoine("Antoine", 150);
        std::cout << Antoine << std::endl << "incrementing now :\n";
        Antoine.incrementGrade();
        std::cout << Antoine << std::endl<< "decrementing now :\n";
        Antoine.decrementGrade();
        std::cout << Antoine << std::endl;

        std::cout << "==Decrementing grade again, should see exception now :==\n\n";

        Antoine.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}