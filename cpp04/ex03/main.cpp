#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

//Valgrind

int main()
{
    std::cout << "\n\n====TESTS BEGIN====\n\n";

    Character character("Hero");

    Ice* ice = new Ice();
    character.equip(ice);

    Character target("Target");
    character.use(0, target);

    delete ice;

    std::cout << "\n\n====SUBJECT TESTS====\n\n";

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}