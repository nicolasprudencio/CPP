#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog is born" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog &other) {
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog was de americanas" << std::endl;
}

Dog &Dog::operator=(Dog &other) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}