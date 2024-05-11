/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:16 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/11 16:57:33 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed();
	~Fixed();
	Fixed(Fixed& x);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed & operator=(Fixed const &param);

private:

	int	_value;
	static const int _nb_bit = 8;
};

#endif
