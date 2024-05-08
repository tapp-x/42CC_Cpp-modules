/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:28:37 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/08 11:36:50 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_phonebook.hpp"

int main()
{
    Phonebook phone;
    bool my_bool = true;
    std::string prompt = "phonebook >";
    std::string buf = "";
    while(my_bool)
    {
        std::cout << prompt;
        if (std::getline(std::cin, buf))
        {
            if (!buf.compare("ADD"))
                phone.add();
            else if (!buf.compare("SEARCH"))
                phone.search();
            else if (!buf.compare("EXIT"))
            {
                my_bool = false;
                continue;
            }
        }
        if (std::cin.eof() == true)
        {
            std::cout << "ctrl + D pressed : exit" << std::endl;
            _Exit(1);
        }
    }
}