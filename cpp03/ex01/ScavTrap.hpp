#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "Macros.hpp"

class ScavTrap: public ClapTrap {
	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap &other);

		void attack(ScavTrap &target, const int attackDamage);
		void guardGate();
};

#endif