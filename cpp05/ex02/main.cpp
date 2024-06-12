#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "====TESTS BEGIN====\n\n";
    
    ShrubberyCreationForm S("Timon"); //145 137
    RobotomyRequestForm R("Pumba"); //72 45
    PresidentialPardonForm P("Antoine"); //25 5

    Bureaucrat one("One", 150);
    Bureaucrat two("Two", 100);
    Bureaucrat three("Three", 70);
    Bureaucrat four("The People", 1);

    std::cout << "\n-----Should not be able to sign nor execute" << std::endl;

    one.signForm(S);
    one.executeForm(S);

    std::cout << "\n-----Should not execute first, then should sign, then should execute" << std::endl;

    two.executeForm(S);

    std::cout << "\n\n-----now signin and executing : \n";

    two.signForm(S);
    two.executeForm(S);

    std::cout << "\n-----Should be able to sign but not execute" << std::endl;

    three.signForm(R);
    three.executeForm(R);

    std::cout << "\n-----The people have all the power. Should sign and execute all.\n" << std::endl;

    four.signForm(R);
    four.signForm(P);
    four.signForm(S);

    four.executeForm(P);
    four.executeForm(R);
    four.executeForm(S);

    std::cout << "\n-----Randomization of robotomization (lol) : \n\n";
    four.executeForm(R);
    four.executeForm(R);
    four.executeForm(R);
    four.executeForm(R);
    four.executeForm(R);
    four.executeForm(R);

    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}
