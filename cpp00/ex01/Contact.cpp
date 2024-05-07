/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:16:01 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/07 17:46:10 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void) 
{
    std::cout << "construct called" << std::endl;
}

Contact::~Contact(void) 
{
}

void    Contact::init_contact(){
    this->_firstName = get_infos("Enter a firstname");
    this->_lastName = get_infos("Enter a lasttname");
    this->_nickname = get_infos("Enter a nickname");
    this->_phoneNumber = get_infos("Enter a phone number");
    this->_darkestSecret = get_infos("Enter your darkest secret");
}

void    Contact::display_contact() {
    std::cout << "Firstname :" << this->_firstName << std::endl;
    std::cout << "Lasttname :" << this->_lastName << std::endl;
    std::cout << "Nickname :" << this->_nickname << std::endl;
    std::cout << "Phone number :" << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret :" << this->_darkestSecret << std::endl;
}

std::string   Contact::get_infos(std::string prompt) {
    bool my_bool = false;
    std::string buffer;
    while(!my_bool)
    {
        std::cout << prompt << ":";
        if (std::getline(std::cin, buffer))
        {
            if (!buffer.empty())
                my_bool = true;
        }
    }
    return (buffer);
}
