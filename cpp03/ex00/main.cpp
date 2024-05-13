/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:21:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 09:46:26 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct1;
	ClapTrap ct2("test");

	ct1 = ct2;
	// ClapTrap("Emile");

	std::string target1 = "a cat";
	ct1.attack(target1);
	ct2.takeDamage(5);
	ct2.takeDamage(5);
	ct2.takeDamage(5);

	ct2.attack("a target");
	// ct3.beRepaired(3);

	return (0);
}
