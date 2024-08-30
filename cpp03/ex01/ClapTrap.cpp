#include "ClapTrap.hpp"


ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
	std::cout << _name << " was destoyed by ClapTrap" << std::endl;
}

ClapTrap:: ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << _name << " got up" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other) {
	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
	}
	return *this;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

std::string ClapTrap::getName() {
	return _name;
}

int ClapTrap::getHitPoints() {

	if (_name == "Luffy")
	{
		std::cout << RED + _name  + " has " << _hitPoints << " hit points of life!" << RESET << std::endl;
	} else {
		std::cout << PURPLE + _name  + " has " << _hitPoints << " hit points of life!" << RESET << std::endl;
	}
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() {
	return _energyPoints;
}

int ClapTrap::getAttackDamage() {
	return _attackDamage;
}

void ClapTrap::attack(ClapTrap &target, const int attackDamage) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}

	std::cout << _name << " attacks " << target.getName() << " causing a damage of "<< attackDamage << std::endl;

	_energyPoints -= 3;
	target.takeDamage(attackDamage);
}

void ClapTrap::beRepaired(int amount) {\
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}

	_hitPoints += amount;
	_energyPoints -= 1;

	if (_name == "Luffy")
	{
		std::cout << RED << _name << " repaired by " << amount << " points" << RESET << std::endl;
	} else {
		std::cout << PURPLE << _name << " repaired by " << amount << " points" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(int amount) {
	_hitPoints -= amount;
	if (_hitPoints <= 0) {
		std::cout << _name << " died" << std::endl;
	}
}
