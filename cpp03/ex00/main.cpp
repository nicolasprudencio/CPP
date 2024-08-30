#include "ClapTrap.hpp"

int main() {
	ClapTrap Luffy("Luffy");
	ClapTrap Doflamingo("Doflamingo");
	int luffyLife;
	int doflamingoLife;

	Luffy.setAttackDamage(4);
	Doflamingo.setAttackDamage(4);

	int luffyDamage = Luffy.getAttackDamage();
	int DoflamingoDamage = Doflamingo.getAttackDamage();

	while ((luffyLife = Luffy.getHitPoints()) > 0 &&
		(doflamingoLife = Doflamingo.getHitPoints()) > 0)
	{
		if (luffyLife < 4 && luffyLife > 0)
			Luffy.beRepaired(1);
		if (doflamingoLife < 4 && doflamingoLife > 0)
			Doflamingo.beRepaired(1);
		Luffy.attack(Doflamingo, luffyDamage);
		Doflamingo.attack(Luffy, DoflamingoDamage);
	}
	Luffy.getEnergyPoints();
	Doflamingo.getEnergyPoints();

	return 0;
}