/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:54 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/11 17:17:11 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;

	std::cout << "b is " << b << std::endl;

	std::cout << "c is " << c << std::endl;

	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	std::cout << "b is " << b.toInt() << " as integer" << std::endl;

	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
