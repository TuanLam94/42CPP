#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& copy);
        Dog &operator = (const Dog& other);
        Dog(std::string type);
        ~Dog();
        void makeSound(void) const;
};

#endif
