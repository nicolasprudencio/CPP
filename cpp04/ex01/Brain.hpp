#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	public:
		Brain();
		Brain(Brain &Other);
		~Brain();
		Brain& operator=(Brain &other);

	protected:
		std::string _ideas[100];
};

#endif