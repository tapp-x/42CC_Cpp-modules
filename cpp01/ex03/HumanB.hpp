/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:16:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/14 13:50:38 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB {

public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &x);
	Weapon *getWeapon();

private:
	std::string _name;
	Weapon *_weapon;
};

#endif
