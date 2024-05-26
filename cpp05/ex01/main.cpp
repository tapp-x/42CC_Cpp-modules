/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/25 20:33:11 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Chris", 5);
        try {
            std::cout << bureaucrat << std::endl;

            std::cout << "Setting grade to 100 by recreating Bureaucrat" << std::endl;
            Bureaucrat bureaucrat100("Chris", 100);
            std::cout << bureaucrat100 << std::endl;


            //Uncoment to test invalid grade
            // std::cout << "Setting grade to 0 by recreating Bureaucrat" << std::endl;
            // Bureaucrat bureaucrat0("Chris", 0);
            // std::cout << bureaucrat0 << std::endl;

            std::cout << "Setting grade to 3 by recreating Bureaucrat" << std::endl;
            Bureaucrat bureaucrat3("Chris", 3);
            std::cout << bureaucrat3 << std::endl;

            std::cout << "Incrementing grade" << std::endl;
            bureaucrat3.incrementGrade();
            std::cout << bureaucrat3 << std::endl;

            std::cout << "Incrementing grade again" << std::endl;
            bureaucrat3.incrementGrade();
            std::cout << bureaucrat3 << std::endl;

            std::cout << "Incrementing grade beyond valid range" << std::endl;
            bureaucrat3.incrementGrade();
            std::cout << bureaucrat3 << std::endl;

            //Uncoment to test invalid grade
            // std::cout << "Setting grade to 150 by recreating Bureaucrat" << std::endl;
            // Bureaucrat bureaucrat150("Chris", 150);
            // std::cout << bureaucrat150 << std::endl;

            std::cout << "Decrementing grade" << std::endl;
            bureaucrat3.decrementGrade();
            std::cout << bureaucrat3 << std::endl;

            return 0;
        } catch(const std::exception& except) {
            std::cerr << except.what() << std::endl;
            return 1;
        }
    } catch(const std::exception& except) {
        std::cerr << except.what() << std::endl;
        return 1;
    }
}

