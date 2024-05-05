/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:54:31 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/05 18:57:01 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t x = 0; x < str.length(); x++)
		{
			str[x] = toupper(str[x]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
}
