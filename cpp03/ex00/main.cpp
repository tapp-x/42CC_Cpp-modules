/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:21:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/22 18:11:36 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("BobClapTrap");

	std::cout << std::endl;
	std::cout << "Attack empty target:" << std::endl;
	claptrap.attack("");
	std::cout << "Attack with target:" << std::endl;
	for (int i = 0; i < 5; i++)
		claptrap.attack("test");
	std::cout << std::endl;

	std::cout << "Take damage with invalid amount:" << std::endl;
	claptrap.takeDamage(-1001);
	std::cout << "Take damage with 0 amount:" << std::endl;
	claptrap.takeDamage(0);
	std::cout << "Take damage with valid amount:" << std::endl;
	for (int i = 0; i < 5; i++)
		claptrap.takeDamage(5);
	std::cout << std::endl;

	std::cout << "Repair with invalid amount:" << std::endl;
	claptrap.beRepaired(-10);
	std::cout << "Repair with 0 amount:" << std::endl;
	claptrap.beRepaired(0);
	std::cout << "Repair with valid amount:" << std::endl;
	for (int i = 0; i < 6; i++)
		claptrap.beRepaired(1);
	std::cout << std::endl;
	return (0);
}
