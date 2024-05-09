/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:41:49 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 14:23:58 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

public:
	Zombie(std::string);
	Zombie();
	~Zombie();
	void	annonce();
	void	set_name(std::string name);

private:
	std::string _name;
};

Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif
