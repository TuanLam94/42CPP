#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal &operator = (const WrongAnimal& other);
        WrongAnimal(std::string type);
        ~WrongAnimal();
        void setType(std::string type);
        std::string getType(void) const;
        void makeSound(void) const;
};

#endif
