/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:21:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/22 17:53:33 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// int main()
// {
// 	ScavTrap test("Emile");
// 	test.takeDamage(7);
// 	test.beRepaired(10);
// 	test.guardGate();
// 	test.attack("a pizza");
// 	std::cout << "HP : " << test.get_hit_point()  << std::endl;

// 	ScavTrap t2;
// 	t2 = test;

// 	test.takeDamage(100);
// 	t2.attack("random");

// 	std::cout << "HP : " << test.get_hit_point() << std::endl;
// 	test.attack("nothing");

// 	return (0);
// }


int main()
{
	ClapTrap claptrap("BobClapTrap");

	std::cout << std::endl;
	std::cout << "Attack empty target:" << std::endl << "	";
	claptrap.attack("");
	std::cout << "Attack with target:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "	";
		claptrap.attack("test");
	}
	std::cout << std::endl;

	std::cout << "Take damage with invalid amount:" << std::endl << "	";
	claptrap.takeDamage(-1001);
	std::cout << "Take damage with 0 amount:" << std::endl << "	";
	claptrap.takeDamage(0);
	std::cout << "Take damage with valid amount:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "	";
		claptrap.takeDamage(5);
	}
	std::cout << std::endl;

	std::cout << "Repair with invalid amount:" << std::endl << "	";
	claptrap.beRepaired(-10);
	std::cout << "Repair with 0 amount:" << std::endl << "	";
	claptrap.beRepaired(0);
	std::cout << "Repair with valid amount:" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "	";
		claptrap.beRepaired(1);
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "#####NEW CHALLENGER#####:" << std::endl;
	std::cout << "     ScavTrap appears.." << std::endl;
	std::cout << "#####NEW CHALLENGER#####:" << std::endl;
	std::cout << std::endl;

	ScavTrap scavtrap("BobScavTrap");
	std::cout << std::endl;
	std::cout << "Attack empty target:" << std::endl << "	";
	scavtrap.attack("");
	std::cout << "Attack with target:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "	";
		scavtrap.attack("test");
	}
	std::cout << std::endl;

	std::cout << "Take damage with invalid amount:" << std::endl << "	";
	scavtrap.takeDamage(-1001);
	std::cout << "Take damage with 0 amount:" << std::endl << "	";
	scavtrap.takeDamage(0);
	std::cout << "Take damage with valid amount:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "	";
		scavtrap.takeDamage(5);
	}
	std::cout << std::endl;

	std::cout << "Repair with invalid amount:" << std::endl << "	";
	scavtrap.beRepaired(-10);
	std::cout << "Repair with 0 amount:" << std::endl << "	";
	scavtrap.beRepaired(0);
	std::cout << "Repair with valid amount:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "	";
		scavtrap.beRepaired(1);
	}
	std::cout << std::endl;
	std::cout << "Guard Gate:" << std::endl << "	";
	scavtrap.guardGate();
	std::cout << std::endl;






	return (0);
}
