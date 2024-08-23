#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	public:

		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap &other);

		void attack(ClapTrap &target, const int attackDamage);
		void takeDamage(int amount);
		void beRepaired(int amount);
		int getHitPoints();
		std::string getName();
		int getAttackDamage();
		void setAttackDamage(int attackDamage);
		void setEnergyPoints(int attackDamage);
		//implementar beRepaired

	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif