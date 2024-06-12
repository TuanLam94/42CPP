#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat& executor);
        void setTarget(std::string target);
};

#endif