#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
#include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(AAnimal &Other);
		virtual ~AAnimal();
		AAnimal& operator=(AAnimal &other);

		std::string getType() const;
		virtual void makeSound() const = 0;

	protected:
		std::string _type;
};

#endif