/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:00:40 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:08:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
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
