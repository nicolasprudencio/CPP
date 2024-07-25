/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:29:16 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 22:59:10 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/ZombieHorde.hpp"

int main() {
	int n = 5;
	Zombie* horde = zombieHorde(n, "ZombieHorde");

	if (horde != NULL) {
		for (int i = 0; i < n; i++) {
			horde[i].announce();
		}
		delete[] horde;
		return 0;
	}
	std::cerr << "Failed to create zombie horde." << std::endl;
	return 1;
}
