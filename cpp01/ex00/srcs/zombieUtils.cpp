/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:28:05 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 22:36:38 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombieUtils.hpp"

Zombie* newZombie(const std::string &name) {
	return new Zombie(name);
}

void randomChump(const std::string &name) {
	Zombie Z(name);
	Z.announce();
}