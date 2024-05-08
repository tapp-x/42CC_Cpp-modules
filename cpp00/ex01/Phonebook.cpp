/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:26:46 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/08 11:38:05 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->index = 0;
}

Phonebook::~Phonebook(void)
{
}

void    Phonebook::add(){
    this->_contact[this->index % 8].init_contact();
    this->index++;
}

void    Phonebook::search(){
    if (this->index == 0)
    {
        std::cout << "No contact is registered" << std::endl;
        return ;
    }
    if (this->index > 0)
    {
        std::cout << "|-------------------------------------------|" << std::endl;
        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    }
    int i = 0;
    int stop = this->index % 8;
    if  (this->index >= 8)
        stop = 8;
    while(i < stop)
    {
        std::cout << "|-------------------------------------------|" << std::endl;
        this->print_line(i);
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        i++;
    }
    bool during = true;
    std::string buff;
    while(during)
    {
        std::cout << "Enter an index : ";
        if (std::getline(std::cin, buff))
        {
            if (atoi(buff.c_str()) > 0 && atoi(buff.c_str()) < 9)
            {
                if ((atoi(buff.c_str()) > stop))
                    std::cout << "Not enough contacts registered" << std::endl;
                else
                    this->_contact[atoi(buff.c_str()) - 1].display_contact();
            }
            else
                std::cout << "Invalid nb index : exit SEARCH" << std::endl;
            during = false;
            continue;
        }
        if (std::cin.eof() == true)
        {
            std::cout << "ctrl + D pressed : exit" << std::endl;
            _Exit(1);
        }   
    }
}

void Phonebook::print_line(int index)
{
    std::string f_name = this->_contact[index].get_firstname();
    std::string l_name = this->_contact[index].get_lastname();
    std::string n_name = this->_contact[index].get_nickname();

    std::cout << "|" << std::setw(10) << index + 1 << "|";
    
    if (f_name.length() >= 10)
        std::cout << f_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << f_name << "|";
    if (l_name.length() >= 10)
        std::cout << l_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << l_name << "|";
    if (n_name.length() >= 10)
        std::cout << n_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << n_name << "|" << std::endl;
}