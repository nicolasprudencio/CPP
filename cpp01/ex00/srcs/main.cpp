/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:29:16 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 22:36:23 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "../includes/zombieUtils.hpp"

int main() {
	
	Zombie* heapZombie = newZombie("Michael Jackson");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Fresh Prince");
	
	return 0;
}

// Stack:

// Usar a pilha é mais rápido e a memória é automaticamente liberada quando o escopo é termina.
// Próprio para objetos que só precisam existir temporariamente dentro de uma função, como no caso de randomChump.
// Heap:

// Usar a heap permite que o objeto viva além do escopo em que foi criado, porém devemos gerenciar a memória manualmente (usando new e delete).
// Próprio para objetos que precisam persistir após a função terminar, como no caso de newZombie.