/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:26:48 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 22:33:09 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEUTILS_HPP
# define ZOMBIEUTILS_HPP

#include "Zombie.hpp"

Zombie* newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif