#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria* _source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource &operator=(const MateriaSource& other);
        ~MateriaSource();
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif