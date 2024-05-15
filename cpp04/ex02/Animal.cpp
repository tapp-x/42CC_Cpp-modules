/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:34:01 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 15:43:22 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "None";
}

Animal::~Animal() {
	std::cout << "Destructor (for animal) called" << std::endl;
}

Animal::Animal(Animal const &cpy) {
	std::cout << "Copy constructor (for animal) called" << std::endl;
	this->type = cpy.type;
}

Animal & Animal::operator=(Animal const &equal) {
	std::cout << "Assignation operator (for animal) called" << std::endl;
	this->type = equal.getType();
	return (*this);
}

// void Animal::makeSound() const  {
//     std::cout << "Basic animal song : RRRRRRR" << std::endl;
// }

const std::string&  Animal::getType(void) const{
    return (this->type);
}
