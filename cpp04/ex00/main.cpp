#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongDog();
	const WrongAnimal* wrongI = new WrongCat();

	wrongMeta->makeSound();
	wrongJ->makeSound();
	wrongI->makeSound();

	delete wrongMeta;
	delete wrongJ;
	delete wrongI;
	return 0;
}