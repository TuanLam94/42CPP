#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    private:
        Brain *_Brain;
    public:
        Dog();
        Dog(const Dog& copy);
        Dog &operator = (const Dog& other);
        Dog(std::string type);
        ~Dog();
        void makeSound(void) const;
};

#endif
