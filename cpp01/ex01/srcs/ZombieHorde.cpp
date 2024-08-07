/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:47:10 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 21:23:22 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ZombieHorde.hpp"

Zombie* zombieHorde(int n, const std::string &name) {
	if (n <= 0) return NULL;

	Zombie* horde = new Zombie[n];
	for (int i = 0; i < n ; i++) {
		horde[i].setName(name + char(i + 48));
	}

	return horde;
}