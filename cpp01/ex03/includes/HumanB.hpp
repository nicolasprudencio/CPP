/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:21:48 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 21:40:23 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB {

	public:
		HumanB(const std::string& name) : _name(name), _weapon(NULL) {};

		void setWeapon(Weapon& weapon);

		void attack(void) const;

	private:
		std::string _name;
		Weapon* _weapon; // Pointer to Weapon
};

#endif