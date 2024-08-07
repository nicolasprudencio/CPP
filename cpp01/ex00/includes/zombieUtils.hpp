/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:26:48 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 21:16:49 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEUTILS_HPP
# define ZOMBIEUTILS_HPP

#include "Zombie.hpp"
#include <string>

Zombie* newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif