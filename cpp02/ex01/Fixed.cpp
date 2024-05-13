/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 17:01:27 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &x) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = x._value;
}

Fixed & Fixed::operator=(Fixed const &param) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = param.getRawBits();
	return (*this);
}

Fixed::Fixed(const int int_nb) : _value(int_nb << _nb_bit) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fl_nb) : _value((int)roundf(fl_nb * (1 << _nb_bit))) {
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat() const {
	return (float)this->_value / (1 << this->_nb_bit);
}

int	Fixed::toInt() const {
	return (this->_value  >> this->_nb_bit);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}