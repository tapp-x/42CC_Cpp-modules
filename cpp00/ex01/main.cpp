/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:28:37 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/07 17:58:07 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

#include <iostream>

int main()
{
    Phonebook phone;
    // Contact test;
    // test.init_contact();
    // std::cout << "now display" << std::endl;
    // test.display_contact();
    std::string buf = "";
    while(buf.compare("EXIT"))
    {
        if (!buf.compare("ADD"))
            phone.add();
        else if (!buf.compare("SEARCH"))
            phone.search();
        else
            std::cout << "Invalid input try again" << std::endl;
        std::cout << "phonebook >";
        std::cin >> buf;
    }
}