#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &other) {
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain &other) {
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}
