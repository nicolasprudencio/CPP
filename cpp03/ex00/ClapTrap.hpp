#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	public:

		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(ClapTrap &target, const int attackDamage);
		void takeDamage(int amount);
		void beRepaired(int amount);
		void getHitPoints();
		std::string getName();

	private:

		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif