/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 16:03:55 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal 
{
public:
    Cat();
    ~Cat();

    Cat(Cat const &x);
	Cat & operator=(Cat const &param);

    void makeSound();
};

#endif
