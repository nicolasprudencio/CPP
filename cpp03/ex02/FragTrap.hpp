#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap& operator=(FragTrap &other);

		void highFivesGuys(FragTrap &other);
};

#endif