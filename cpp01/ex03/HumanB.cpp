/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:18:31 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:24:22 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "violence.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << "destructor called" << std::endl;
}

void	HumanB::attack() {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &x){
	this->_weapon = &x;
}

Weapon	*HumanB::getWeapon() {
	return (this->_weapon);
}