#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {};

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	setAttackDamage(20);
	if (name == "Luffy") {
		std::cout << name << " Gear Fourth!" << std::endl;
	} else {
		std::cout << name << " Is in ito ito no Mi awaken!" << std::endl;
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
	if (_name == "Luffy") {
		std::cout << _name << " Gomu Gomu Kong Gun!  " << target._name << " causing a damage of "<< attackDamage << std::endl;
	} else {
		std::cout << _name << " Senbon no Ya: Flap Thread!" << std::endl;
	}

	setEnergyPoints(-3);
	target.takeDamage(attackDamage);
}