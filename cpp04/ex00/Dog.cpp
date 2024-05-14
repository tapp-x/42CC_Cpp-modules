/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:34:21 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 16:01:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &x) : Animal(x){
	std::cout << "Copy Dog constructor called" << std::endl;
	this->type = x.type;
}

Dog & Dog::operator=(Dog const &param) {
	std::cout << "Assignation Dog operator called" << std::endl;
	this->type = param.getType();

	return (*this);
}

void Dog::makeSound() {
    std::cout << "Woof!" << std::endl;
}
