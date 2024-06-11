#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
    _type = "Cat";
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat string constructor called\n";
    _type = type;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
    *this = copy;
}

Cat &Cat::operator = (const Cat& other)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound(void) const
{
    std::cout << "Meow !\n";
}
