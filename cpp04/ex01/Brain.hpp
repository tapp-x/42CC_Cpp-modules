/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:07:39 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/23 14:38:53 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(Brain const &cpy);
		Brain & operator=(Brain const &cpy);
		~Brain();
		
		void setIdeas(const std::string &idea, int index);
    	std::string getIdeas(int index) const;

	private:
		std::string ideas[100];
};

#endif

