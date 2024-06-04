#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called\n";
    _Brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog string constructor called\n";
    _Brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy), _Brain(new Brain(*copy._Brain))
{
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator = (const Dog& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete _Brain;
        _Brain = new Brain (*other._Brain);
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
