#include "ClapTrap.hpp"

int main() {
	ClapTrap Luffy("Luffy");
	ClapTrap Doflamingo("Doflamingo");

	Luffy.setAttackDamage(5);
	Doflamingo.setAttackDamage(4);

	int luffyDamage = Luffy.getAttackDamage();
	int DoflamingoDamage = Doflamingo.getAttackDamage();

	while (Luffy.getHitPoints() > 0 && Doflamingo.getHitPoints() > 0) {
		Doflamingo.attack(Luffy, DoflamingoDamage);
		Luffy.attack(Doflamingo, luffyDamage);
	}

	return 0;
}