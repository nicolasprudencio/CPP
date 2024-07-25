/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:21:48 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 23:25:55 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
	public:
		HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

		void setWeapon(Weapon& weapon) {
			_weapon = &weapon;
		}

		void attack() const {
			if (_weapon) {
				std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
			} else {
				std::cout << _name << " has no weapon to attack with!" << std::endl;
			}
		}

	private:
		std::string _name;
		Weapon* _weapon; // Pointer to Weapon
};

#endif