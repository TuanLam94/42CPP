#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
    return (_name);
}

int Bureaucrat::getGrade()
{
    return (_grade);
}

