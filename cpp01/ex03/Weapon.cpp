/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:18:44 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 19:18:26 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "violence.hpp"

Weapon::Weapon(std::string firsttype) {
	this->type = firsttype;
}

Weapon::~Weapon() {}

void	Weapon::setType(std::string newType) {
	this->type = newType;
}

const std::string Weapon::getType() {
	return (this->type);
}
