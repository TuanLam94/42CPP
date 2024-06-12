#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "====TESTS BEGIN====\n\n";

    Intern someRandomIntern;
    Form* rr;
    rr = someRandomIntern.makeForm("robotomy request", "Bender");

    Form* pp;
    pp = someRandomIntern.makeForm("presidential pardon", "Bender");

    Form* sc;
    sc = someRandomIntern.makeForm("shrubbery creation", "Bender");

    Form* noexist;
    noexist = someRandomIntern.makeForm("no exist", "Bender");

    std::cout << "\n-- poor Bender !--\n";

    std::cout << "\n\n====TESTING IF FORMS HAVE THE RIGHT ATTRIBUTES====\n\n";

    Bureaucrat a("Thomas", 60);

    a.signForm(*pp);
    a.signForm(*rr);
    a.signForm(*sc);
    a.executeForm(*pp);
    a.executeForm(*rr);
    a.executeForm(*sc);

    delete rr;
    delete pp;
    delete sc;
    delete noexist;

    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}