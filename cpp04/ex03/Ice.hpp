/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:29 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 13:10:11 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();

		Ice(Ice const &cpy);
		Ice & operator=(Ice const &cpy);

		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
		 
	private:
};

#endif
