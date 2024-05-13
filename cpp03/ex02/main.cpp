/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:21:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 10:20:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap test1("Emile");
	test1.takeDamage(7);
	test1.beRepaired(10);
	test1.highFivesGuys();
	test1.attack("a pizza");
	std::cout << "HP : " << test1.get_hit_point()  << std::endl;

	test1.takeDamage(100);

	std::cout << "HP : " << test1.get_hit_point() << std::endl;
	test1.attack("nothing");

	ScavTrap test("Emile");
	test.takeDamage(7);
	test.beRepaired(10);
	test.guardGate();
	test.attack("a pizza");
	std::cout << "HP : " << test.get_hit_point()  << std::endl;

	ScavTrap t2;
	t2 = test;

	test.takeDamage(100);
	t2.attack("random");

	std::cout << "HP : " << test.get_hit_point() << std::endl;
	test.attack("nothing");

	return (0);

	return (0);
}
