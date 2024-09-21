#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat &Other);
		~WrongCat();
		WrongCat &operator=(WrongCat &Other);
		void makeSound() const;

};

#endif