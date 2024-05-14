/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:01 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 16:05:23 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// #include "Cat.hpp"
// #include "Dog.hpp"

class Animal {
protected:
    std::string type;

public:
    Animal();
	virtual ~Animal();
    
	Animal(const Animal& copy);
	Animal& operator=(const Animal &equal);
    
	virtual void        makeSound() const;
	const std::string&  getType(void) const;
};

#endif