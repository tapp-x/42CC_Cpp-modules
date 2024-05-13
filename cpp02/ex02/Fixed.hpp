/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:16 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:20 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	//constructor
	Fixed();
	Fixed(Fixed const &x);
	Fixed(const int int_nb);
	Fixed(const float fl_nb);

	//destructor
	~Fixed();

	//methods
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	// operator overload
	Fixed & operator=(Fixed const &param);
	
	bool operator>(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;
	
	Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

	Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int); 

	//static functions
	static Fixed min(Fixed &a, Fixed &b);
    static Fixed min(Fixed const &a, Fixed const &b);
    static Fixed max(Fixed &a, Fixed &b);
    static Fixed max(Fixed const &a, Fixed const &b);
	
private:

	int	_value;
	static const int _nb_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
