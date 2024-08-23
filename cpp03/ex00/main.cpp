#include "ClapTrap.hpp"

int main() {
	ClapTrap Luffy("Luffy");
	ClapTrap DonFlamingo("Don Flamingo");

	Luffy.setAttackDamage(5);
	DonFlamingo.setAttackDamage(4);

	int luffyDamage = Luffy.getAttackDamage();
	int DonFlamingoDamage = DonFlamingo.getAttackDamage();

	while (Luffy.getHitPoints() > 0 && DonFlamingo.getHitPoints() > 0) {
		DonFlamingo.attack(Luffy, DonFlamingoDamage);
		Luffy.attack(DonFlamingo, luffyDamage);
	}

	return 0;
}