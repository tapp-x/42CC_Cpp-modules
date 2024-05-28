/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:27:35 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/28 15:39:59 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Constructor Intern called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Deconstructor Intern called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Constructor copy Intern called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {}
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; ++i) {
        if (formTypes[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        delete forms[i];
    }
    std::cout << "Form name " << formName << " not recognized" << std::endl;
    return NULL;
}
