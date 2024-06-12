#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
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