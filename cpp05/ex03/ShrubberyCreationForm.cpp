/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:00:04 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/28 15:09:40 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
        std::cout << "Constructor ShrubberyCreationForm called" << std::endl;
    }

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy), _target(copy._target) {
        std::cout << "Copy Constructor ShrubberyCreationForm called" << std::endl;
    }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Assign operator ShrubberyCreationForm called" << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!this->is_signed())
        throw AForm::FormNotSignedException();
    if (executor.get_grade() > this->get_exec_grade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (ofs.fail()) {
        std::cerr << "Failed to create the shrubbery file." << std::endl;
        return;
    }

    ofs << "          &&& &&  & &&" << std::endl;
    ofs << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    ofs << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    ofs << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    ofs << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    ofs << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    ofs << "   ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    ofs << "               &&     \\|||" << std::endl;
    ofs << "                         |||" << std::endl;
    ofs << "                         |||" << std::endl;
    ofs << "                         |||" << std::endl;
    ofs.close();
}
