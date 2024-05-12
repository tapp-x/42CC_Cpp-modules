/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:12:48 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/12 19:39:34 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default constructor called for ScavTrap" << std::endl;
	this->_Attack_dammage = 20;
	this->_Hit_point = 100;
	this->_Energy_point = 50;;
}

ScavTrap::ScavTrap(std::string new_name)
{
	std::cout << "New ScavTrap created with name : " << new_name << std::endl;
	this->_name = new_name;
	this->_Attack_dammage = 20;
	this->_Hit_point = 100;
	this->_Energy_point = 50;
}

ScavTrap::ScavTrap(ScavTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap : " << this->_name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &param) {
	std::cout << "Assignation operator called" << std::endl;
	this->_name = param.get_name();
	this->_Attack_dammage = param.get_attack_point();
	this->_Hit_point = param.get_hit_point();
	this->_Energy_point = param.get_energy_point();
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
	else if (this->_Energy_point <= 0)
	{
		std::cout << "Not enought energy to attack with ScavTrap : " << this->_name << std::endl;
		return ;
	}
	else if (this->_Attack_dammage <= 0)
	{
		std::cout << "Not enought attack_dmg to attack with ScavTrap : " << this->_name << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " \
		<< target << ", causing " << this->_Attack_dammage << " points of damage!" << std::endl;
	this->_Energy_point--;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (amount == 0)
	{
		std::cout << "A ScavTrap can't take less than 1 damage" << std::endl;
		return ;
	}
	this->_Hit_point -= amount;
	std::cout << "ScavTrap : " << this->_name << " lost " << amount << " HP !" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
	if (amount <= 0)
	{
		std::cout << "A ScavTrap can't gain less than 1 HP" << std::endl;
		return ;
	}
	this->_Hit_point += amount;
	std::cout << "ScavTrap : " << this->_name << " gain " << amount << " HP !" << std::endl;
	this->_Energy_point--;
}

void	ScavTrap::guardGate() {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do noting..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
