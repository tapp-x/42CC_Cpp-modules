/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:16 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 16:50:07 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed();
	~Fixed();
	Fixed(Fixed const &x);
	
	Fixed & operator=(Fixed const &param);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:

	int	_value;
	static const int _nb_bit = 8;
};

#endif
