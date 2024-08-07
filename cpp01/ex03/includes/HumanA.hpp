/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:21:17 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 22:01:44 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA {
	public:
		HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}

		void attack (void) const;

	private:
		std::string _name;
		Weapon& _weapon; // Reference to Weapon
};

#endif