#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat is born" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other) {
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat was de americanas" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &other) {
	std::cout << "WrongCat copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}