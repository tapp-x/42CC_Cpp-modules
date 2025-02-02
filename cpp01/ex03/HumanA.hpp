/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:14:30 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:21:57 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {

public:
	HumanA(std::string name, Weapon &x);
	~HumanA();
	void	attack();
	Weapon &getWeapon();

private:
	std::string _name;
	Weapon &_weapon;
};

#endif
