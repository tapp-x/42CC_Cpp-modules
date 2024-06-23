/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:34:21 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 15:06:24 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    type = "Dog";
	brain = new Brain();
    // std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
    // std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal(cpy){
	// std::cout << "Copy Dog constructor called" << std::endl;
	this->brain = new Brain(*cpy.brain);;
	*this = cpy;
}

Dog & Dog::operator=(Dog const &param) {
	// std::cout << "Assignation Dog operator called" << std::endl;
	this->type = param.getType();
	return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}

void Dog::setBrain(Brain *src)
{
	delete this->brain;
	this->brain = src;
}