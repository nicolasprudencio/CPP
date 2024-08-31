#include "Cat.hpp"

Cat::Cat() {}
Cat::Cat(std::string name): _name(name) {
	std::cout << _name << " the Cat is born" << std::endl;
	std::vector<std::string> animalTypes = {"Dog", "Cat"};

	for (int i = 0; i < animalTypes.size(); i++) {
		if (name == animalTypes[i])
			_type = animalTypes[i];
	}
}

Cat::~Cat() {
	std::cout << _name << " the Cat was de americanas" << std::endl;
}

Cat &Cat::operator=(Cat &other) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &other) {
		_name = other._name;
		_type = other._type;
	}
	return *this;
}