/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:51:23 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/02 12:55:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, std::size_t length, void (*function)(T&)) {
    for (std::size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

#endif
