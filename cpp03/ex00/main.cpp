#include "ClapTrap.hpp"

int main() {
	ClapTrap Luffy("Luffy");
	ClapTrap DonFlamingo("Don Flamingo");

	Luffy.getHitPoints();
	DonFlamingo.getHitPoints();
	Luffy.attack(DonFlamingo, 10);

	return 0;
}