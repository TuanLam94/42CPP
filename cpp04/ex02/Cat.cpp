#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
    _Brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat string constructor called\n";
    _Brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal (copy), _Brain(new Brain (*copy._Brain))
{
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator = (const Cat& other)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete _Brain;
        _Brain = new Brain (*other._Brain);
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
