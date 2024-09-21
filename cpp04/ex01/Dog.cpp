#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog is born" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(Dog &other): _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog was de americanas" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog &other) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}