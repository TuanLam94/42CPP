#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
    protected :
        AMateria* _inventory[4];
    public :
        Character();
        Character(const Character& copy);
        Character &operator = (const Character& other);
        ~Character();
        Character(std::string name);
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int i);
        void use(int i, ICharacter& target);
};

#endif