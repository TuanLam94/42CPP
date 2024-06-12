#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat& executor);
};

#endif