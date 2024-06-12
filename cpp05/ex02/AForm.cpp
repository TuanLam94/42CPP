#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed = other.getSigned();
    }
    return (*this);
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExec() const
{
    return _gradeToExec;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _gradeToSign) {
        _signed = true;
        std::cout << _name << " was signed by " << b.getName() << std::endl;
    }
    else
        throw GradeTooLowException();
}

std::ostream& operator << (std::ostream& os, const AForm& AForm)
{
    os << AForm.getName() << " is signed : " << AForm.getSigned() << " to be signed : " << AForm.getGradeToSign() << " to be executed : " << AForm.getGradeToExec() << std::endl;
    return os;
}
