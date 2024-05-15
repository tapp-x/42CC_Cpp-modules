/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:27:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:15:36 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main ()
{
	AMateria *a = new Ice();

    AMateria *b = a->clone();
    std::cout << b->getType() << std::endl;

    AMateria *c = new Cure();
    b = c->clone();
    std::cout << b->getType() << std::endl;
}
