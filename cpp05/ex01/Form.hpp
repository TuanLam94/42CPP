#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form& copy);
        Form &operator=(const Form& other);
        ~Form();
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        void beSigned(Bureaucrat& b);

        //Exceptions classes
        class GradeTooHighException : public std::exception 
        {
            public: 
                const char *what() const throw()
                {
                    return "Grade is too high!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Grade is too low!";
                }
        };
};

std::ostream& operator << (std::ostream& os, const Form& Form);

#endif