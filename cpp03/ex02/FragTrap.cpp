/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:05:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:30:56 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default constructor called for FragTrap" << std::endl;
	this->_Attack_dammage = 30;
	this->_Hit_point = 100;
	this->_Energy_point = 100;;
}

FragTrap::FragTrap(std::string new_name)
{
	std::cout << "New FragTrap created with name : " << new_name << std::endl;
	this->_name = new_name;
	this->_Attack_dammage = 30;
	this->_Hit_point = 100;
	this->_Energy_point = 100;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap : " << this->_name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &param) {
	std::cout << "Assignation operator called" << std::endl;
	this->_name = param.get_name();
	this->_Attack_dammage = param.get_attack_point();
	this->_Hit_point = param.get_hit_point();
	this->_Energy_point = param.get_energy_point();
	return (*this);
}

void    FragTrap::highFivesGuys() {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
    std::cout << this->_name << " make a High Fives !" << std::endl;
}
