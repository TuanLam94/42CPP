#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout << "WrongAnimal string constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    *this = copy;
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal& other)
{
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::setType(std::string type)
{
    _type = type;
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Moooh !\n";
}
