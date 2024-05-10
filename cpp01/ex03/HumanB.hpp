/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:16:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:23:13 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

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
