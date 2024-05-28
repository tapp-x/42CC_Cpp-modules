/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/28 15:01:51 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat chris("Chris", 5);
        Bureaucrat alex("Alex", 100);
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << chris << std::endl;
        std::cout << alex << std::endl;
        std::cout << bob << std::endl;

        chris.signForm(shrubbery);
        chris.signForm(robotomy);
        chris.signForm(pardon);

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        chris.executeForm(shrubbery);
        chris.executeForm(robotomy);
        chris.executeForm(pardon);

        alex.signForm(robotomy);
        alex.executeForm(robotomy);

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

    } catch (const std::exception& except) {
        std::cerr << except.what() << std::endl;
        return (1);
    }

    return (0);
}