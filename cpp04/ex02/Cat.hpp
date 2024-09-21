#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal {
	public:
		Cat();
		Cat(Cat &Other);
		~Cat();
		Cat &operator=(Cat &Other);

		void makeSound() const;
	private:
		Brain *_brain;

};

#endif