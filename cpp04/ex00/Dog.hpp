/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 16:04:38 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
public:
    Dog();
    ~Dog();

    Dog(Dog const &x);
	Dog & operator=(Dog const &param);

    void makeSound();
};

#endif