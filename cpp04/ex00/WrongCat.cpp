/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:34:35 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 13:51:39 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    // std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    // // std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &x) : WrongAnimal(x) {
	// // std::cout << "Copy WrongCat constructor called" << std::endl;
	this->type = x.type;
}

WrongCat & WrongCat::operator=(WrongCat const &param) {
	// // std::cout << "Assignation WrongCat operator called" << std::endl;
	this->type = param.getType();

	return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Miaouu!" << std::endl;
}
