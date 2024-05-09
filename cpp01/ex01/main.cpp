/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:39:21 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 14:42:58 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	int N = 5;
	std::string name = "ZOMBAR";
	Zombie *tab = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		tab[i].annonce();
	}
	delete[] tab;
}
