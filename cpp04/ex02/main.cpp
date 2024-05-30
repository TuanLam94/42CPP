#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

////VALGRIND TO CHECK

int main()
{

    std::cout << "\n\n==== TESTS BEGIN ====\n\n";

    // Animal a; //Does not work as the class is Abstract

    Dog b;
    Cat c;

    std::cout << "\n\n==== TESTING IF EVERYTHING WORKS AS BEFORE ====\n\n";

    Animal* array[10];

    for (int i = 0; i < 5; i++) {
        array[i] = new Dog();
    }
    for (int j = 5; j < 10; j++) {
        array[j] = new Cat();
    }

    for (int y = 0; y < 10; y++) {
        array[y]->makeSound();
    }

    std::cout << "\n\n==== DELETING EVERYONE ====\n\n";

    for (int k = 0; k < 10; k++) {
        delete array[k];
    }

    std::cout << "\n\n==== SUBJECT TESTS ====\n\n";

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "\n\n ==== TESTS END ====\n\n";

    return (0);
}
