#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;


	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;

	const Animal* Animal[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			Animal[i] = new Dog();
		else
			Animal[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
	{	
		Animal[i]->makeSound();
		delete Animal[i];
	}

	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}