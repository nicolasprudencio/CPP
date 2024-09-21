#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(Dog &Other);
		~Dog();
		Dog &operator=(Dog &Other);


		void makeSound() const;
	private:
		Brain *_brain;
};

#endif