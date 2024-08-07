/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:15:52 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 21:20:04 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

	private:
		std::string _name;

	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();
		void announce() const;
		void setName(const std::string &name);

};

#endif