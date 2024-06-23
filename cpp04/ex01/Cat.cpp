/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:33:41 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 15:06:51 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
	brain = new Brain();
    // std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
    // std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy) {
	// std::cout << "Copy Cat constructor called" << std::endl;
	this->brain = new Brain(*cpy.brain);;
	*this = cpy;
}

Cat & Cat::operator=(Cat const &param) {
	// std::cout << "Assignation Cat operator called" << std::endl;
	this->type = param.getType();

	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Miaouu!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}

void Cat::setBrain(Brain *src)
{
	delete this->brain;
	this->brain = src;
}