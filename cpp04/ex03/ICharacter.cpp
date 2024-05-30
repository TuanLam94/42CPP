#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    _name = new std::string("");
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

ICharacter::ICharacter(std::string name)
{
    _name = new std::string(name);
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

ICharacter::ICharacter(const ICharacter& copy)
{
    delete _name;
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    _name = new std::string(*copy._name);
    for (int i = 0; i < 4; i++) {
        if (copy._inventory[i]) {
            _inventory[i] = copy._inventory[i].clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

ICharacter &ICharacter::operator = (const ICharacter& other)
{
    if (this != &other) {
        delete _name;
        _name = new std::string (*other._name);
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

ICharacter::~ICharacter()
{
    delete _name;
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
}