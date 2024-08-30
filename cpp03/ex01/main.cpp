#include "ScavTrap.hpp"

int main() {
	ScavTrap Luffy("Luffy");
	ScavTrap Doflamingo("Doflamingo");
	int luffyLife;
	int doflamingoLife;

	Luffy.setAttackDamage(5);
	Doflamingo.setAttackDamage(4);

	int luffyDamage = Luffy.getAttackDamage();
	int DoflamingoDamage = Doflamingo.getAttackDamage();
	std::cout << std::endl << std::endl;

	while ((luffyLife = Luffy.getHitPoints()) > 0 &&
		(doflamingoLife = Doflamingo.getHitPoints()) > 0)
	{
		Doflamingo.attack(Luffy, DoflamingoDamage);
		Luffy.attack(Doflamingo, luffyDamage);
		std::cout << std::endl << std::endl;

		if (luffyLife <= 10)
			Luffy.beRepaired(3);
		if (doflamingoLife <= 10)
			Doflamingo.beRepaired(3);
	}
	return 0;
}