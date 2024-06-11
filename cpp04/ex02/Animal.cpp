#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

Animal::Animal() { std::cout << "Animal constructor called\n"; }

Animal::Animal(std::string type) {
  _type = type;
  std::cout << "Animal string constructor called\n";
}

Animal::Animal(const Animal &copy) {
  *this = copy;
  std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignment operator called\n";
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called\n"; }

void Animal::setType(std::string type) { _type = type; }

std::string Animal::getType(void) const { return (_type); }

void Animal::makeSound(void) const {
  if (_type == "Cat") {
    std::cout << "Meow !\n";
  } else if (_type == "Dog") {
    std::cout << "Bark !\n";
  } else
    std::cout << "Neither a dog nor a cat\n";
}
