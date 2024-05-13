/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:30:54 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 17:58:07 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;	

 	Fixed a2;
    Fixed const b2(Fixed(19.19f) * Fixed(3));

    std::cout << "Valeur initiale de a2 : " << a2 << std::endl;
    std::cout << "Va2leur de b2 : " << b2 << std::endl;

    std::cout << "Pré-incrementation de a2 : " << ++a2 << std::endl;
    std::cout << "Valeur de a après pré-incrementation : " << a2 << std::endl;

    std::cout << "Post-incrementation de a2 : " << a2++ << std::endl;
    std::cout << "Valeur de a après post-incrementation : " << a2 << std::endl;

    std::cout << "Comparaison de a2 et b2 : " << std::endl;
    std::cout << "a2 > b2 : " << (a2 > b2) << std::endl;
    std::cout << "a2 < b2 : " << (a2 < b2) << std::endl;
    std::cout << "a2 == b2 : " << (a2 == b2) << std::endl;

    std::cout << "Max de a2 et b2 : " << Fixed::max(a2, b2) << std::endl;
    std::cout << "Min de a2 et b2 : " << Fixed::min(a2, b2) << std::endl;
	return 0;
}
