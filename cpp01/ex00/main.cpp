/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:39:21 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/08 18:48:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	std::cout << "We are gona create Zombies !" << std::endl;

	std::string a = "call 1";
	std::string b = "call 2";

	std::cout << "Enter randomChump, let's create and annonce a Zombie" << std::endl;
	randomChump(a);
	std::cout << "Exit randomChump, destroy this one" << std::endl;

	std::cout << "Enter randomChump, let's create and annonce a Zombie" << std::endl;
	randomChump(b);
	std::cout << "Exit randomChump, destroy this one" << std::endl;

	std::cout << "Create a zombie with newZombie" << std::endl;
	std::string c = "call 3";
	Zombie *p = newZombie(c);
	p->annonce();
	delete p;
}
