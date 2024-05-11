/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:49 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 17:24:54 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(std::string level) {
    void        (Harl::*ptr_function[4])(void);
    std::string choice[4];

    choice[0] = "DEBUG";
    choice[1] = "INFO";
    choice[2] = "WARNING";
    choice[3] = "ERROR";

    ptr_function[0] = &Harl::debug;
    ptr_function[1] = &Harl::info;
    ptr_function[2] = &Harl::warning;
    ptr_function[3] = &Harl::error;

	int i = 0;
    while(i <= 4)
    {
        if (level == choice[i])
            break;
		i++;
    }
	switch (i)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		this->debug();
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		this->info();
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		this->warning();
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		this->error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void    Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-";
    std::cout << "ketchup burger. I really do!" << std::endl;
}

void    Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning() {
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for";
    std::cout << "years whereas you started working here since last month." << std::endl;
}

void    Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
