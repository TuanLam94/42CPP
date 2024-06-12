#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

//ENLEVER VIRTUAL VOID USE DANS ICE ET CURE ?

// static AMateria* poubelle[128];
// A chaque fois qu'on cree une materia sans l'equiper, on la met dans la poubelle
// A chaque fois qu'on desequipe une materia on la met dans la poubelle
// A la fin, on delete toute la poubelle.


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
    delete tmp;
    tmp = NULL;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    delete tmp;
    tmp = NULL;

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    me->unequip(1);

    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n\n====FURTHER TESTING====\n\n";

    Character one;

    Character two(one);

    Character three = two;

    std::cout << "name : " << two.getName() << std::endl;


    std::cout << "\n\n====TESTS END====\n\n";

    return 0;
}