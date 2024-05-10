/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:49 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:55:27 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(std::string level) {
    void        (Harl::*ptr_function[4])(void);
    std::string choice[4];

    choice[0] = "debug";
    choice[1] = "info";
    choice[2] = "warning";
    choice[3] = "error";

    ptr_function[0] = &Harl::debug;
    ptr_function[1] = &Harl::info;
    ptr_function[2] = &Harl::warning;
    ptr_function[3] = &Harl::error;

    for (int i = 0;i  < 4; i++)
    {
        if (level == choice[i])
            (this->*ptr_function[i])();
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