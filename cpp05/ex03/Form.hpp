#ifndef Form_HPP
#define Form_HPP

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
        virtual ~Form();
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) = 0;
        virtual void setTarget(std::string target) = 0;

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

std::ostream& operator << (std::ostream& os, const Form& Form);

#endif