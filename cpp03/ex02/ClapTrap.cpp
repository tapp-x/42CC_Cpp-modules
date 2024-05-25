/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:22:17 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/22 18:38:01 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->_Attack_dammage = 0;
	this->_Hit_point = 10;
	this->_Energy_point = 10;;
}

ClapTrap::ClapTrap(std::string new_name) {
	std::cout << "New ClapTrap created with name : " << new_name << std::endl;
	this->_name = new_name;
	this->_Attack_dammage = 0;
	this->_Hit_point = 10;
	this->_Energy_point = 10;
}

ClapTrap::ClapTrap(ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for ClapTrap : " << this->_name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &param) {
	std::cout << "Assignation operator called" << std::endl;
	this->_name = param.get_name();
	this->_Attack_dammage = param.get_attack_point();
	this->_Hit_point = param.get_hit_point();
	this->_Energy_point = param.get_energy_point();
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (target.empty())
	{
		std::cout << " Try to attack but target is empty" << std::endl;
		return ;
	}
	if (this->_Hit_point <= 0)
	{
		std::cout << this->_name << " is already dead and can't do nothing..." << std::endl;
		return ;
	}
	if (this->_Energy_point <= 0)
	{
		std::cout << "Not enought energy to attack with ClapTrap : " << this->_name << std::endl;
		return ;
	}
	else if (this->_Attack_dammage <= 0)
	{
		std::cout << "Try to attack: " << target << " but not enough attack_dmg " << this->_name << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " \
		<< target << ", causing " << this->_Attack_dammage << " points of damage!" << std::endl;
	this->_Energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_Hit_point <= 0)
	{
		std::cout << this->get_name() << " is already dead, stop attack him !" << std::endl;
		return ;
	}
	if ((int)amount <= 0)
	{
		std::cout << "A ClapTrap can't take less than 1 damage" << std::endl;
		return ;
	}
	if (amount >= this->get_hit_point())
		this->_Hit_point = 0;
	else
		this->_Hit_point -= amount;
	std::cout << "ClapTrap : " << this->_name << " lost " << amount << " HP !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if ((int)amount <= 0)
	{
		std::cout << "A ClapTrap can't gain less than 1 HP" << std::endl;
		return ;
	}
	this->_Hit_point += amount;
	std::cout << "ClapTrap : " << this->_name << " gain " << amount << " HP !" << std::endl;
	this->_Energy_point--;
}

unsigned int ClapTrap::get_attack_point() const{
	return (this->_Attack_dammage);
}

unsigned int ClapTrap::get_hit_point() const{
	return (this->_Hit_point);
}

unsigned int ClapTrap::get_energy_point() const{
	return (this->_Energy_point);
}

std::string ClapTrap::get_name() const{
	return (this->_name);
}
