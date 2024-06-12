#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm& copy);
        AForm &operator=(const AForm& other);
        ~AForm();
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) = 0;

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
        class NotSignedException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form is not signed!";
                }
        };
};

std::ostream& operator << (std::ostream& os, const AForm& AForm);

#endif