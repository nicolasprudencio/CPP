#include "ClapTrap.hpp"


ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
	std::cout << _name << " was destoyed by ClapTrap" << std::endl;
}

ClapTrap:: ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100) {
	std::cout << _name << " got up" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other) {
	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
	}
	return *this;
}

std::string ClapTrap::getName() {
	return _name;
}

void ClapTrap::attack(ClapTrap &target, const int attackDamage) {
	std::cout << _name << " attacks " << target.getName() << " causing a damage of "<< attackDamage << std::endl;

	_energyPoints -= 3;
	target.takeDamage(attackDamage);
}

int ClapTrap::getAttackDamage() {
	return _attackDamage;
}

int ClapTrap::getHitPoints() {
	std::cout << _name << " has " << _hitPoints << " hit points of life!" << std::endl;
	return _hitPoints;
}



void ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::beRepaired(int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}

	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << _name << " repaired by " << amount << " points" << std::endl;
}


void ClapTrap::takeDamage(int amount) {
	_hitPoints -= amount;
	if (_hitPoints <= 0) {
		std::cout << _name << " died" << std::endl;
	}
}
