#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : Form(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
    if (!getSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    else {
        std::string outputFile = _target + "_shrubbery";
        std::ofstream outputStream(outputFile.c_str());
        if (!outputStream.is_open()) {
            std::cerr << "Can't open" << outputFile << "\n";
            return ;
        }
        outputStream << "            8" << std::endl;
        outputStream << "           / \\" << std::endl;
        outputStream << "          /   \\" << std::endl;
        outputStream << "         /     \\" << std::endl;
        outputStream << "        5       10" << std::endl;
        outputStream << "       / \\      / \\" << std::endl;
        outputStream << "      2   6    9   11" << std::endl;
    }
}

void ShrubberyCreationForm::setTarget(std::string target) {
    _target = target;
}