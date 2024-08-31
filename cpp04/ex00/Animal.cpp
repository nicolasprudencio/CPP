#include "Animal.hpp"
#include <vector>

Animal::Animal() {}
Animal::Animal(std::string type) {
	std::vector<std::string> animalTypes = {"Dog", "Cat"};

	for (int i = 0; i < animalTypes.size(); i++) {
		if (type == animalTypes[i]) {
			_type = type;
			return;
		}
	}
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal &other) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void Animal::makeSound() {
	std::cout << "Make a " << _type << "'s sound" << std::endl;
}

