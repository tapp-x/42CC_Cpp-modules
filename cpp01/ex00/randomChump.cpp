/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:41:28 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/08 18:38:43 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ){
	std::cout << "Enter randomChump, let's create and annonce a Zombie" << std::endl;
	Zombie first_z = Zombie(name);
	first_z.annonce();
	std::cout << "Exit randomChump, destroy this one" << std::endl;
}
