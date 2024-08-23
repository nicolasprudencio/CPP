#include "ScavTrap.hpp"

int main() {
	ScavTrap Luffy("Luffy");
	ScavTrap Doflamingo("Doflamingo");
	ScavTrap Luffy2;

	Luffy.setAttackDamage(5);
	Doflamingo.setAttackDamage(4);
	Luffy2 = Luffy;



	int luffyDamage = Luffy.getAttackDamage();
	int DoflamingoDamage = Doflamingo.getAttackDamage();

	while (Luffy.getHitPoints() > 0 && Doflamingo.getHitPoints() > 0) {
		Doflamingo.attack(Luffy, DoflamingoDamage);
		Doflamingo.setAttackDamage(DoflamingoDamage);
		Luffy.attack(Doflamingo, luffyDamage);
		Luffy.setAttackDamage(luffyDamage);
		luffyDamage = luffyDamage * 2;
		DoflamingoDamage = DoflamingoDamage * 1.3;
	}

	return 0;
}