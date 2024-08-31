#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
#include <vector>
# include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(std::string name);
		~Cat();
		Cat &operator=(Cat &Other);
		
	private:
		std::string _name;
};

#endif