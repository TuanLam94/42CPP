#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    protected :
        AMateria* _inventory[4];
    public :
        Character();
        Character(const ICharacter& copy);
        Character &operator = (const ICharacter& other);
        ~Character();
        Character(std::string name);
        virtual std::string const& getName() const;
        virtual AMateria& getInventorySlot() const = 0;
        virtual void equip(AMateria* m);
        virtual void unequip(int i);
        virtual void use(int i, ICharacter& target);
};

#endif