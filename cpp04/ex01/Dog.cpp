#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called\n";
    _type = "Dog";
    _Brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog string constructor called\n";
    _type = type;
    _Brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
    std::cout << "Dog copy constructor called\n";
    *this = copy;
}

Dog &Dog::operator = (const Dog& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other) {
        _type = other._type;
        _Brain = other._Brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete _Brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Bark !\n";
}
