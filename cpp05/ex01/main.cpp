/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 15:36:14 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Chris", 5);
        try {
            std::cout << bureaucrat << std::endl;

            std::cout << "Creating Form1 with sign grade 3 and exec grade 5" << std::endl;
            Form form1("Form1", 3, 5);
            std::cout << form1 << std::endl;

            std::cout << "Creating Form2 with sign grade 100 and exec grade 50" << std::endl;
            Form form2("Form2", 100, 50);
            std::cout << form2 << std::endl;

            std::cout << "Chris attempts to sign Form1" << std::endl;
            bureaucrat.signForm(form1);
            std::cout << form1 << std::endl;

            std::cout << "Creating Bureaucrat with grade 100" << std::endl;
            Bureaucrat bureaucrat100("Alex", 100);
            std::cout << bureaucrat100 << std::endl;

            std::cout << "Alex attempts to sign Form2" << std::endl;
            bureaucrat100.signForm(form2);
            std::cout << form2 << std::endl;

            std::cout << "Incrementing grade of Alex" << std::endl;
            bureaucrat100.incrementGrade();
            std::cout << bureaucrat100 << std::endl;

            std::cout << "Alex attempts to sign Form2 again" << std::endl;
            bureaucrat100.signForm(form2);
            std::cout << form2 << std::endl;

            // Uncomment to test invalid form creation
            // std::cout << "Creating a form with invalid sign grade 0" << std::endl;
            // Form invalidForm("InvalidForm", 0, 5);

            std::cout << "Decrementing grade of Chris" << std::endl;
            bureaucrat.decrementGrade();
            std::cout << bureaucrat << std::endl;

            std::cout << "Chris attempts to sign Form1 again" << std::endl;
            bureaucrat.signForm(form1);
            std::cout << form1 << std::endl;

            return 0;
        } catch (const std::exception& except) {
            std::cerr << except.what() << std::endl;
            return 1;
        }
    } catch (const std::exception& except) {
        std::cerr << except.what() << std::endl;
        return 1;
    }
}
