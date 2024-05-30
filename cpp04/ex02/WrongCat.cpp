#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() 
{
    std::cout << "WrongCat constructor called\n";
    _type = "WrongCat";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat string constructor called\n";
    _type = type;
}

WrongCat::WrongCat(const WrongCat& copy)
{
    std::cout << "WrongCat copy constructor called\n";
    *this = copy;
}

WrongCat &WrongCat::operator = (const WrongCat& other)
{
    std::cout << "WrongCat assignment operator called\n";
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow !\n";
}
