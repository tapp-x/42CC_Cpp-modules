/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:13:45 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/31 16:16:12 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base::~Base() {}

Base* generate() {
    srand(static_cast<unsigned int>(time(0)));
    int randVal = rand() % 3;

    switch (randVal) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return (NULL);
    }
}

void identifyPtr(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identifyRef(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}
