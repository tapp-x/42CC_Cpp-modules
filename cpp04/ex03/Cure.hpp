/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 13:10:04 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();

		Cure(Cure const &cpy);
		Cure & operator=(Cure const &cpy);

		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
	private:
};

#endif
