/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:13:55 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/31 15:31:17 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "ASerializer constructor called" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "ASerializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& src) {
	std::cout << "ASerializer copy constructor called" << std::endl;
    *this = src;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return (*this); 
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}