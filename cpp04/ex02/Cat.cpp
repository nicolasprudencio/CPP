#include "Cat.hpp"

Cat::Cat(): AAnimal() {
	std::cout << "Cat is born" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(Cat &other): AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat was de americanas" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Cat &Cat::operator=(Cat &other) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}