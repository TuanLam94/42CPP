#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& other);
        ~Bureaucrat();
        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm& form) const;
        void executeForm(AForm& form) const;

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

std::ostream& operator << (std::ostream& os, const Bureaucrat& Bureaucrat);

#endif