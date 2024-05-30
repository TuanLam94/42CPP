#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal& copy);
        Animal &operator = (const Animal& other);
        Animal(std::string type);
        virtual ~Animal();
        void setType(std::string type);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif
