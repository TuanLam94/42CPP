#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    private:
        Brain *_Brain;
    public:
        Cat();
        Cat(const Cat& copy);
        Cat &operator = (const Cat& other);
        Cat(std::string type);
        ~Cat();
        void makeSound(void) const;
};

#endif
