#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        void execute(const Bureaucrat& executor);
        void setTarget(std::string target);
};

#endif