/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:21:41 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/12 19:17:55 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:

	std::string 	_name;
	unsigned int	_Hit_point;
	unsigned int	_Energy_point;
	unsigned int	_Attack_dammage;

public:
	ClapTrap();
	ClapTrap(std::string new_name);
	ClapTrap(ClapTrap &copy);
	~ClapTrap();
	ClapTrap & operator=(ClapTrap const &param);

	unsigned int	get_hit_point() const;
	unsigned int	get_energy_point() const;
	unsigned int	get_attack_point() const;
	std::string		get_name() const;

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
};

#endif
