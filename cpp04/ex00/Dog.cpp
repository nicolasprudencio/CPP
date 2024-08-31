#include "Dog.hpp"

Dog::Dog() {}
Dog::Dog(std::string name): _name(name) {
	std::cout << _name << " the Dog is born" << std::endl;
	std::vector<std::string> types = {"Dog", "Cat"};

	for (int i = 0; i < types.size(); i++) {
		if (name == types[i])
			_type = name;
	}
}

Dog::~Dog() {
	std::cout << _name << " the Dog was de americanas" << std::endl;
}

Dog &Dog::operator=(Dog &other) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &other) {
		_name = other._name;
		_type = other._type;
	}
	return *this;
}