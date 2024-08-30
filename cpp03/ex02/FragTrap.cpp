#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {};

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	setAttackDamage(20);
	if (name == "Luffy") {
		std::cout << name << " Im Hungry!" << std::endl;
	} else {
		std::cout << name << " Aaaaah. i wanna take some sleep!" << std::endl;
	}
};

FragTrap::~FragTrap() {
	std::cout << getName() << " was destroyed by FragTrap" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &other) {
	std::cout << "FragTrap Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
	}
	return *this;
}

void FragTrap::highFivesGuys(FragTrap &other) {
	std::cout << getName() << " hi fives with " << other.getName() << std::endl;
}
