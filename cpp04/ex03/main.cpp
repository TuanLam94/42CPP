#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    Character character("Hero");

    Ice* ice = new Ice();
    character.equip(ice);

    Character target("Target");
    character.use(0, target);

    delete ice;

    return 0;
}