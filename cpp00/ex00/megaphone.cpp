/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:34:37 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/17 22:50:17 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void handleMegaphone(char **argv, int argc);

int main(int argc, char **argv)
{
	if (argc > 1)
		handleMegaphone(argv, argc);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}


void handleMegaphone(char **argv, int argc)
{
	std::string str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
}
