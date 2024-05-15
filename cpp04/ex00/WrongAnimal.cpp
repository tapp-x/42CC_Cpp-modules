/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:58:38 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 13:09:24 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	this->type = "None";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor (for Wronganimal) called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &x) {
	std::cout << "Copy constructor (for Wronganimal) called" << std::endl;
	this->type = x.type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &param) {
	std::cout << "Assignation operator (for Wronganimal) called" << std::endl;
	this->type = param.getType();

	return (*this);
}

void	WrongAnimal::makeSound() const  {
    std::cout << "Basic Wronganimal song : RRRRRRR" << std::endl;
}

const std::string&  WrongAnimal::getType(void) const{
    return (this->type);
}
