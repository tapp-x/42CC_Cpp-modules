/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 14:52:45 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();

    Cat(Cat const &x);
	Cat & operator=(Cat const &param);

    void makeSound() const;
    Brain *getBrain() const;
    void setBrain(Brain *brain);

private:
	Brain *brain;
};

#endif
