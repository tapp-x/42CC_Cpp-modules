/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 16:06:01 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.cpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
 
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
 
    i->makeSound(); //will output the cat sound!
    j->makeSound();
 
    meta->makeSound();
    return 0;
}