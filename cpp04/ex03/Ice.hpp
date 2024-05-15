/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:29 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:07:48 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "Materia.hpp"

class Ice : public AMateria
{
	public:
		Ice();

		Ice(Ice const &cpy);
		Ice & operator=(Ice const &cpy);

		~Ice();

		 AMateria* clone() const;
	private:
};

#endif
