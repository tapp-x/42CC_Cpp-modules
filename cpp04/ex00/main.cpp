/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/18 13:41:22 by tappourc         ###   ########.fr       */
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
    const Animal* doggy = new Dog();
    const Animal* kitty = new Cat();

    std::cout << doggy->getType() << std::endl;
    std::cout << kitty->getType() << std::endl;

    kitty->makeSound();
    doggy->makeSound();
    meta->makeSound();

	const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();

    std::cout << x->getType() << std::endl;

    x->makeSound();

    wrongmeta->makeSound();

    delete doggy;
    delete kitty;
    delete meta;
    delete wrongmeta;
    delete x;

    return (0);
}
