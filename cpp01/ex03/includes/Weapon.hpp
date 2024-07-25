/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:18:45 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 23:20:21 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	public:
		Weapon(const std::string& type = "") : _type(type) {}

		const std::string& getType() const {
			return _type;
		}

		void setType(const std::string& type) {
			_type = type;
		}

	private:
		std::string _type;
};

#endif