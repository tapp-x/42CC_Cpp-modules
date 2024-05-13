/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:16 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 17:00:17 by tappourc         ###   ########.fr       */
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

private:

	int	_value;
	static const int _nb_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
