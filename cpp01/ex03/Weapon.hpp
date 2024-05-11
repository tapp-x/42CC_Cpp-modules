/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:17:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/11 13:40:25 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {

public:
	Weapon(std::string firsttype);
	~Weapon();
	void	setType(std::string newtype);
	const std::string getType();

private:
	std::string _type;

};

#endif
