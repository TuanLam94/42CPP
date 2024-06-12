#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& copy);
        Intern &operator=(const Intern& other);
        ~Intern();
        Form* makeForm(std::string name, std::string target);
        Form* createShrubbery(std::string target);
        Form* createRobotomy(std::string target);
        Form* createPresidential(std::string target);
};

typedef Form* (Intern::*FunctionPtr) (std::string target);

#endif