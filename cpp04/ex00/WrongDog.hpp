#ifndef WrongDog_HPP
# define WrongDog_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongDog: public WrongAnimal {
	public:
		WrongDog();
		WrongDog(WrongDog &Other);
		~WrongDog();
		WrongDog &operator=(WrongDog &Other);
		void makeSound() const;
};

#endif