#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed = other.getSigned();
    }
    return (*this);
}

Form::~Form() {}

const std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExec() const
{
    return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _gradeToSign) {
        _signed = true;
        std::cout << _name << " was signed by " << b.getName() << std::endl;
    }
    else
        throw GradeTooLowException();
}

std::ostream& operator << (std::ostream& os, const Form& Form)
{
    os << Form.getName() << " is signed : " << Form.getSigned() << " to be signed : " << Form.getGradeToSign() << " to be executed : " << Form.getGradeToExec() << std::endl;
    return os;
}
