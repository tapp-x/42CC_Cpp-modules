/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 14:52:51 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();

    Dog(Dog const &x);
	Dog & operator=(Dog const &param);

    void makeSound() const ;
    Brain *getBrain() const;
    void setBrain(Brain *brain);

private:
	Brain *brain;
};

#endif
