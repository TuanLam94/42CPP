#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other){
        _grade = other._grade;
        // _name = other.getName();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(Form& form) const
{
    try {
        form.beSigned(*this);
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form& form) const
{
    try {
        form.execute(*this);
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& Bureaucrat)
{
    return (os << Bureaucrat.getName() << ", Bureaucrat grade :" << Bureaucrat.getGrade() << std::endl); 
}