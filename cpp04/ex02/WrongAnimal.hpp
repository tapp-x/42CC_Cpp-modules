/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:28 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 13:09:12 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
	virtual ~WrongAnimal();

	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal &equal);

	void makeSound() const;
	const std::string&  getType(void) const;
};

#endif
