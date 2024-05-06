/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:01:45 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/06 18:28:25 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void) {
    std::cout << "This is a constructor" << std::endl;
}

Contact::~Contact(void) {
    std::cout << "This is a destructor" << std::endl;
}