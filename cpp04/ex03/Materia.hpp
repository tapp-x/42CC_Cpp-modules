/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:28:57 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 16:56:31 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>

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
		~AMateria();

		//MEMBER FUNCTION & METHODS
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;

		//not yet implemented
		// virtual void use(ICharacter& target);
};

#endif

