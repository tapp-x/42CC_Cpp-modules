/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:08:16 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 14:38:01 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called." << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	std::cout << "Brain Copy constructor called." << std::endl;
	*this = cpy;
}

Brain & Brain::operator=(Brain const &cpy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;
}
