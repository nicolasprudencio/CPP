/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:20:23 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 22:45:52 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce() const {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	_name = name;
}