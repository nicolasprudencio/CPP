#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	// AAnimal* meta = new AAnimal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();

	// delete meta;
	delete j;
	delete i;

	return 0;
}