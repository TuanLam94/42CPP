#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& copy)
{
    *this = copy;
    std::cout << "Brain copy constructor called\n";
}

Brain &Brain::operator = (const Brain& other)
{
    std::cout << "Brain assignment operator called\n";
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}