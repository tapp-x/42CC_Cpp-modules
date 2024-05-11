/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:18:44 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/11 13:40:40 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "violence.hpp"

Weapon::Weapon(std::string firsttype) {
	this->_type = firsttype;
}

Weapon::~Weapon() {}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}

const std::string Weapon::getType() {
	return (this->_type);
}
