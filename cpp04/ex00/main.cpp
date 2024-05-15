/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 13:49:30 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

	const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();

    std::cout << x->getType() << " " << std::endl;

    x->makeSound(); //will output the cat sound!

    wrongmeta->makeSound();
    return 0;
}
