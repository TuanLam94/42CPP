#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called\n";
    _type = "Dog";
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog string constructor called\n";
    _type = type;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
    *this = copy;
}

Dog &Dog::operator = (const Dog& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void) const
{
    std::cout << "Bark !\n";
}
