/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:12:53 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 19:17:32 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "violence.hpp"

// int main ()
// {
// 	Weapon a, b, c;
// 	a.setType("Uzi");
// 	b.setType("Glock");

// 	HumanA test = HumanA("Jonnhy", a);
// 	HumanB second = HumanB("Felix");
// 	second.set_weapon(&b);
// 	HumanB third = HumanB("Carl");

// 	test.attack();
// 	second.attack();
// 	third.attack();
// }

int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
	return 0;
}
