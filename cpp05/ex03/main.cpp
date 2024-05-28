/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/28 15:54:22 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Bob", 5);
        Intern intern;

        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        AForm* form2 = intern.makeForm("presidential pardon", "Trump");
        AForm* form3 = intern.makeForm("shrubbery creation", "Tree");

        if (form1) {
            std::cout << *form1 << std::endl;
            bureaucrat.signForm(*form1);
            bureaucrat.executeForm(*form1);
            delete form1;
        }

        if (form2) {
            std::cout << *form2 << std::endl;
            bureaucrat.signForm(*form2);
            bureaucrat.executeForm(*form2);
            delete form2;
        }

        if (form3) {
            std::cout << *form3 << std::endl;
            bureaucrat.signForm(*form3);
            bureaucrat.executeForm(*form3);
            delete form3;
        }

    } catch (const std::exception& except) {
        std::cerr << except.what() << std::endl;
    }

    return 0;
}

