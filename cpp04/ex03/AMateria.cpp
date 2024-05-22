/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:12 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:18 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor (type include) called." << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const &cpy)
{
	std::cout << "AMateria Copy constructor called." << std::endl;
	*this = cpy;
}

AMateria & AMateria::operator=(AMateria const &cpy)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	this->type = cpy.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called." << std::endl;

}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "Using AMateria" << std::endl;
}