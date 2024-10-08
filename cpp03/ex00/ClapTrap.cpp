#include "ClapTrap.hpp"


ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
	std::cout << _name << " was destoyed" << std::endl;
}

ClapTrap:: ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << _name << " got up" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other) {
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
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}
	std::cout << _name << " attacks " << target.getName() << " causing a damage of "<< attackDamage << std::endl;

	_energyPoints -= 1;
	target.takeDamage(attackDamage);
}

void ClapTrap::beRepaired(int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << _name << " was repaired by " << amount << " points" << std::endl;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}

int ClapTrap::getAttackDamage() {
	return _attackDamage;
}

void ClapTrap::takeDamage(int amount) {
	_hitPoints -= amount;
	if (_hitPoints <= 0) {
		std::cout << _name << " died" << std::endl;
	}
}

int ClapTrap::getEnergyPoints() {
	std::cout << _name << " has " << _energyPoints << " energy points!" << std::endl;
	return _energyPoints;
}

int ClapTrap::getHitPoints() {
	std::string name;

	std::cout << _name << " has " << _hitPoints << " hit points of life!" << std::endl;
	return _hitPoints;
}