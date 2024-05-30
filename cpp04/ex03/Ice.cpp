#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const& copy) : AMateria(copy) {}

Ice &Ice::operator = (const Ice& other)
{
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone(void) const
{
    return (new Ice(*this)); //So that the clone member variables are properly copied
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}