#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(const AMateria& copy) : _type(copy._type) {}

AMateria &AMateria::operator = (const AMateria& other)
{
    (void)other;
    return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter& target) 
{
    std::cout << "Using Materia on " << target.getName() << ".\n";
}