#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        Cure(const Cure& copy);
        Cure &operator = (const Cure& other);
        virtual ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif