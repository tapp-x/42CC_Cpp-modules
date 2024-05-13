/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:05:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/13 10:11:30 by tappourc         ###   ########.fr       */
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

void FragTrap::attack(const std::string& target) {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
	else if (this->_Energy_point <= 0)
	{
		std::cout << "Not enought energy to attack with FragTrap : " << this->_name << std::endl;
		return ;
	}
	else if (this->_Attack_dammage <= 0)
	{
		std::cout << "Not enought attack_dmg to attack with FragTrap : " << this->_name << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " \
		<< target << ", causing " << this->_Attack_dammage << " points of damage!" << std::endl;
	this->_Energy_point--;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (amount == 0)
	{
		std::cout << "A FragTrap can't take less than 1 damage" << std::endl;
		return ;
	}
	if (amount >= this->get_hit_point())
		this->_Hit_point = 0;
	else
		this->_Hit_point -= amount;
	std::cout << "FragTrap : " << this->_name << " lost " << amount << " HP !" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
	if (amount <= 0)
	{
		std::cout << "A FragTrap can't gain less than 1 HP" << std::endl;
		return ;
	}
	this->_Hit_point += amount;
	std::cout << "FragTrap : " << this->_name << " gain " << amount << " HP !" << std::endl;
	this->_Energy_point--;
}

void    FragTrap::highFivesGuys() {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
    std::cout << this->_name << " make a High Fives !" << std::endl;
}