/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:05:21 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "Materia.hpp"

class Cure : public AMateria
{
	public:
		Cure();

		Cure(Cure const &cpy);
		Cure & operator=(Cure const &cpy);

		~Cure();

		 AMateria* clone() const;
	private:
};

#endif
