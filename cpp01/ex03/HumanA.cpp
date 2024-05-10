/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:18:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:22:12 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "violence.hpp"

HumanA::HumanA(std::string name, Weapon &x) : _name(name), _weapon(x) {}

HumanA::~HumanA() {
	std::cout << "destructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

Weapon	&HumanA::getWeapon() {
	return (this->_weapon);
}