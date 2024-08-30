#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {};

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::string born_message;

	if (name == "Luffy") {
		born_message = RED + name + " Gear Fours!" + RESET;
		std::cout << born_message << std::endl;
	} else {
		born_message = PURPLE + name + " Is in ito ito no Mi awaken!" + RESET;
		std::cout << born_message << std::endl;
	}
};

ScavTrap::~ScavTrap() {
	std::cout << getName() << " was destroyed by ScavTrap" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other) {
	std::cout << "ScavTrap Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << getName() << " is now pistola and in gate keeper mode" << std::endl;
}

void ScavTrap::attack(ScavTrap &target, const int attackDamage) {
	std::string luffy;
	std::string doflamingo;

	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return;
	}

	if (_name == "Luffy") {
		luffy = RED + _name + RESET;
		doflamingo = PURPLE + target._name + RESET;

		std::cout << luffy << " Gomu Gomu Kong Gun! causing " << attackDamage << " damage to " + doflamingo << std::endl;
	} else {
		doflamingo = PURPLE + _name + RESET;
		luffy = RED + target._name + RESET;
		
		std::cout << doflamingo << " Senbon no Ya: Flap Thread! causing " << attackDamage << " damage to " + luffy << std::endl;

	}

	_energyPoints -= 1;
	target.takeDamage(attackDamage);
}