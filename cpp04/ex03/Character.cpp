#include "Character.hpp"

Character::Character()
{
    _name = new std::string("");
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string name)
{
    _name = new std::string(name);
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const ICharacter& copy)
{
    delete _name;
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    _name = new std::string(copy.getName());
    for (int i = 0; i < 4; i++) {
        if (copy._inventory[i]) {
            _inventory[i] = copy._inventory[i].clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character &Character::operator = (const ICharacter& other)
{
    if (this != &other) {
        delete _name;
        _name = new std::string (other.getName());
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i].clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return (*this);
}

Character::~Character()
{
    delete _name;
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
}

std::string const& Character::getName() const
{
    return *_name;
}

AMateria& Character::getInventory() 
{

}

void Character::equip(AMateria* m)
{
    int i = 0;
    while (_inventory[i]) {
        i++;
    }
    _inventory[i] = m;
}

void Character::unequip(int i) //leaks ? 
{
    if (i >= 0 && i < 4)
        _inventory[i] = NULL;
}

void use(int i, ICharacter& target) 
{
    if (i >= 0 && i < 4)
        _inventory[i]->use(target);
}