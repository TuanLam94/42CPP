#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat& executor);
        void setTarget(std::string target);
};

#endif
