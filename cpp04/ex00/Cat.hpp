#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat &Other);
		~Cat();
		Cat &operator=(Cat &Other);

		void makeSound() const;

};

#endif