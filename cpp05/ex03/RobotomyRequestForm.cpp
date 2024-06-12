#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : Form(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor)
{
    if (!getSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    else {
        std::cout << "Bzzz bzzz, who should we robotomize today ? How about you, " << _target << " ?" << std::endl;
        int rand = std::rand() % 2;
        if (rand == 1)
            std::cout << _target << " has been successfully robotomized ! Bip boop !\n";
        else
            std::cout << "Robotomy of " << _target << " failed ! They died in atrocious suffering thanks to you. Good Job !\n";
    }
}

void RobotomyRequestForm::setTarget(std::string target) {
    _target = target;
}