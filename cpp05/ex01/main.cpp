#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "====TESTS BEGIN====\n\n";
    
    Form a("a", 130, 130);
    Form b("b", 100, 100);

    Bureaucrat Antoine("Antoine", 125);
    Bureaucrat Barnabe("Barmane", 95);

    a.beSigned(Antoine);
    std::cout << a << std::endl;

    std::cout << "==Trying to sign b by Antoine, should see exception now:==\n";

    try {
        b.beSigned(Antoine);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << b << std::endl;

    std::cout << "\n==Now let's try with Barnabe, should not see exception :==\n";

    try {
        b.beSigned(Barnabe);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << b << std::endl;

    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}