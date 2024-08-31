#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <vector>

class Dog: public Animal {
	public:
		Dog();
		Dog(std::string name);
		~Dog();
		Animal &operator=(Animal &Other);

	private:
		std::string _name;
};

#endif