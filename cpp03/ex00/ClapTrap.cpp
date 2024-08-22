#include "ClapTrap.hpp"

std::string ClapTrap::getName() {
	return _name;
}


ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
	std::cout << _name << " was destoyed" << std::endl;
}

ClapTrap:: ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10) {
	std::cout << _name << " got up" << std::endl;
}

void ClapTrap::attack(ClapTrap &target, const int attackDamage) {
	std::cout << _name << " attacks " << target.getName() << " causing a damage of "<< attackDamage << std::endl;

	_energyPoints -= 1;
	target.takeDamage(attackDamage);
}

void ClapTrap::takeDamage(int amount) {
	_hitPoints -= amount;
	if (_hitPoints <= 0) {
		std::cout << _name << " died" << std::endl;
	}
}

void ClapTrap::getHitPoints() {
	std::cout << _name << " has " << _hitPoints << " hit points of life!" << std::endl;
}