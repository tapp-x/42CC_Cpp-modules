/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:33:41 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 14:34:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
	a_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete a_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &x) : Animal(x) {
	std::cout << "Copy Cat constructor called" << std::endl;
	this->type = x.type;
}

Cat & Cat::operator=(Cat const &param) {
	std::cout << "Assignation Cat operator called" << std::endl;
	this->type = param.getType();

	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Miaouu!" << std::endl;
}
