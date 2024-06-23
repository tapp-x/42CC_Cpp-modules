/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 15:25:23 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	{
		Animal* animals[10];

		for (int i = 0; i < 5; ++i)
			animals[i] = new Dog();
		for (int i = 5; i < 10; ++i)
			animals[i] = new Cat();
		for (int i = 0; i < 10; ++i) {
			animals[i]->makeSound();
			delete (animals[i]);
		}
    }
	{
		std::cout << std::endl;
		Dog* dog1 = new Dog();
		dog1->makeSound();
		dog1->getBrain()->setIdeas("Chase the cat", 0);
		std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdeas(0) << std::endl;

		Dog* dog2 = new Dog(*dog1);
		std::cout << "Dog2 (after copy) Idea[0]: " << dog2->getBrain()->getIdeas(0) << std::endl;

		dog1->getBrain()->setIdeas("Guard the house", 0);
		std::cout << "Dog1 (after modification) Idea[0]: " << dog1->getBrain()->getIdeas(0) << std::endl;
		std::cout << "Dog2 (should be unchanged) Idea[0]: " << dog2->getBrain()->getIdeas(0) << std::endl;

		std::cout << std::endl << "Now cat part" << std::endl << std::endl;
		Cat* cat1 = new Cat();
		cat1->makeSound();
		cat1->getBrain()->setIdeas("Climb the tree", 0);
		std::cout << "Cat1 Idea[0]: " << cat1->getBrain()->getIdeas(0) << std::endl;

		Cat* cat2 = new Cat(*cat1);
		std::cout << "Cat2 (after copy) Idea[0]: " << cat2->getBrain()->getIdeas(0) << std::endl;

		cat1->getBrain()->setIdeas("Sleep in the sun", 0);
		std::cout << "Cat1 (after modification) Idea[0]: " << cat1->getBrain()->getIdeas(0) << std::endl;
		std::cout << "Cat2 (should be unchanged) Idea[0]: " << cat2->getBrain()->getIdeas(0) << std::endl;

		delete (dog1);
		delete (dog2);
		delete (cat1);
		delete (cat2);

		return (0);
	}
}

