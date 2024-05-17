/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:00:40 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 13:24:08 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	this->type = "cure";
	std::cout << "Cure Constructor called." << std::endl;
}

Cure::Cure(Cure const &cpy)
{
	std::cout << "Cure Copy constructor called." << std::endl;
	*this = cpy;
}

Cure & Cure::operator=(Cure const &cpy)
{
	std::cout << "Cure assignation operator called" << std::endl;
	this->type = cpy.getType();
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called." << std::endl;
}

AMateria* Cure::clone() const {
	AMateria *a = new Cure();
	return (a);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}