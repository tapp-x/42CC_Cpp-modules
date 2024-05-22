/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:28:57 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/17 13:44:12 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>
#include "string"

#include "Character.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		//CONSTRUCTOR
		AMateria();
		AMateria(std::string const & type);

		// COPY AND OPERATOR
		AMateria(AMateria const &cpy);
		AMateria & operator=(AMateria const &cpy);

		//DESTRUCTOR
		virtual ~AMateria();

		//MEMBER FUNCTION & METHODS
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif

