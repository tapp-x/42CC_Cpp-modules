/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:09:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:18:22 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice Constructor called." << std::endl;
}

Ice::Ice(Ice const &cpy)
{
	std::cout << "Ice Copy constructor called." << std::endl;
	*this = cpy;
}

Ice & Ice::operator=(Ice const &cpy)
{
	std::cout << "Ice assignation operator called" << std::endl;
	this->type = cpy.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called." << std::endl;
}

AMateria* Ice::clone() const {
	AMateria *a = new Ice();
	return (a);
}
