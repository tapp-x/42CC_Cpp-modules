/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:26:46 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 14:42:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zombTab = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombTab[i].set_name(name);

	}
	return (zombTab);
}
