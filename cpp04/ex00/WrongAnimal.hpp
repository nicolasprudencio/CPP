#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &Other);
		~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal &other);

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;
};

#endif