#include "FragTrap.hpp"

int main() {
	FragTrap Luffy("Luffy");
	FragTrap Zoro("Zoro");


	Luffy.setAttackDamage(30);
	Zoro.setAttackDamage(30);
	Luffy.highFivesGuys(Zoro);

	return 0;
}