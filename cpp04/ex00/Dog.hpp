#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal {
	public:
		Dog();
		Dog(Dog &Other);
		~Dog();
		Dog &operator=(Dog &Other);

		void makeSound() const;
};

#endif