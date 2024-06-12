#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return *this;
}

Intern::~Intern() {}

Form* Intern::createShrubbery(std::string target)
{
    std::cout << "A poor exploited intern created a Shrubbery Creation Form with " << target << " as target.\n";
    return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomy(std::string target)
{
    std::cout << "A poor exploited intern created a Robotomy Request Form with " << target << " as target.\n";
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidential(std::string target)
{
    std::cout << "A poor exploited intern created a Presidential Pardon Form with " << target << " as target.\n";
    return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string name, std::string target)
{
    std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    FunctionPtr ftab[3] = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

    for (int i = 0; i < 3; i++) {
        if (tab[i] == name) {
            return (this->*ftab[i])(target);
        }
    }
    std::cout << "No Form found with this name. Intern went and got a coffee (as they should !)\n";
    return NULL;
}