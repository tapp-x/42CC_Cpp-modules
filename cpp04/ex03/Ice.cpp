/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:09:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 13:00:03 by theoappourc      ###   ########.fr       */
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

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}