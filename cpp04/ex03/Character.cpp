#include "Character.hpp"

Character::Character() : ICharacter()
{
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string name) : ICharacter(name)
{
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& copy) : ICharacter(copy)
{
    // for (int i = 0; i < 4; i++) {
    //     delete _inventory[i];
    // }
    for (int i = 0; i < 4; i++) {
        if (copy._inventory[i]) {
            _inventory[i] = copy._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character &Character::operator = (const Character& other) 
{
    if (this != &other) {
        ICharacter::operator=(other);
        for (int i = 0; i < 4; i++) {
            delete _inventory[i];
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
        }
    }
}

std::string const& Character::getName() const
{
    return *_name;
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while (_inventory[i]) {
        i++;
    }
    if (i < 4) {
        _inventory[i] = m->clone();
    }
    else
        std::cout << "Inventory full !\n";
}

void Character::unequip(int i) //leaks ? 
{
    if (i >= 0 && i < 4)
        _inventory[i] = NULL;
}

void Character::use(int i, ICharacter& target)
{
    if (i >= 0 && i < 4 && _inventory[i])
        _inventory[i]->use(target);
    else
        std::cout << "Can't use Materia\n";
}