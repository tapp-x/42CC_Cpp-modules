/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:51:23 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:53 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, std::size_t length, void (*function)(T const &)) {
	for (std::size_t i = 0; i < length; ++i) {
		function(array[i]);
	}
}

template <typename T>
void print(T const & element) {
	std::cout << element << " ";
}

#endif
