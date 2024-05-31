#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

//Enlever les constructeurs et toute l'implementation car classe abstraite ? 

class IMateriaSource
{
    public:
        IMateriaSource();
        IMateriaSource(const IMateriaSource& copy);
        IMateriaSource &operator=(const IMateriaSource& other);
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif