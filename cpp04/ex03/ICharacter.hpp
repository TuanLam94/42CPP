#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter
{
    protected:
        std::string* _name;
    public:
        ICharacter(std::string name);
        ICharacter();
        ICharacter(const ICharacter& copy);
        ICharacter &operator = (const ICharacter& other);
        virtual ~ICharacter();
        virtual std::string const& getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int i) = 0;
        virtual void use(int i, ICharacter& target) = 0;
};

#endif