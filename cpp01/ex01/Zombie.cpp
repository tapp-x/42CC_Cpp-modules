/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:40:31 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 14:42:37 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::Zombie() {
	std::cout << "construct" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed" << std::endl;
}

void	Zombie::annonce(){
	std::cout << this->_name << " : " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
}
