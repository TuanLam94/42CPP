#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
    _type = "Cat";
    _Brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat string constructor called\n";
    _type = type;
    _Brain = new Brain();
}

Cat::Cat(const Cat& copy)
{
    std::cout << "Cat copy constructor called\n";
    *this = copy;
}

Cat &Cat::operator = (const Cat& other)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &other) {
        _type = other._type;
        _Brain = other._Brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete _Brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow !\n";
}
