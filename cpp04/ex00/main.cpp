#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

////VALGRIND TO CHECK

int main()
{
    std::cout << "==== ANIMAL TESTS ====\n\n";

    Animal Joao;
    Animal Ani = Joao;
    Animal Po;
    Joao.setType("Dog");
    Joao.makeSound();
    Ani.setType("Not a Dog");
    Ani.makeSound();
    Po.makeSound();

    std::cout << "\n\n==== CAT TESTS ====\n\n";
    
    Cat Jonny;
    Cat Jo = Jonny;
    Jonny.makeSound();
    Jo.makeSound();

    std::cout << "\n\n==== DOG TESTS ====\n\n";

    Dog Raoul;
    Dog Ou = Raoul;
    Raoul.makeSound();

    std::cout << "\n\n==== SUBJECT TESTS ====\n\n";

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();

    meta->makeSound();

    std::cout << "\n\n==== WRONG TESTS ====\n\n";

    const WrongAnimal* atem = new WrongAnimal();
    const WrongAnimal* tema = new WrongCat();

    std::cout << tema->getType() << " " << std::endl;

    atem->makeSound();
    tema->makeSound();


    std::cout << "\n\n ==== TESTS END ====\n\n";

    return (0);
}
