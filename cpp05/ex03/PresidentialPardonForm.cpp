#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : Form(copy), _target(copy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor)
{
    if (!getSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    else
        std::cout << _target << " has been pardoned by Zaphod Beeblerox\n";
}

void PresidentialPardonForm::setTarget(std::string target) {
    _target = target;
}