/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:27:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 14:17:06 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

// int main ()
// {
// 	AMateria *a = new Ice();

//     AMateria *b = a->clone();
//     std::cout << b->getType() << std::endl;

//     AMateria *c = new Cure();
//     b = c->clone();
//     std::cout << b->getType() << std::endl;
// }

int main() 
{
    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob"); 
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob; 
    delete me; 
    delete src;
    
    return 0;
}