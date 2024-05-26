/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:26 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/25 20:25:13 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name,  int grade) : _name(name) {
    valid_grade(grade);
    this->_grade = grade;
    std::cout << "Default constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) {
    std::cout << "Copy constructor called for Bureaucrat" << std::endl;
    *this = cpy;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &param) {
    std::cout << "Assignation operator called for Bureaucrat" << std::endl;
    valid_grade(param.get_grade());
    this->_grade =  param.get_grade();
    return (*this);
}

std::string Bureaucrat::get_name() const {
    return (this->_name);
}

int Bureaucrat::get_grade() const {
    return  (this->_grade);
}

void Bureaucrat::valid_grade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

void Bureaucrat::incrementGrade() {
    valid_grade(this->_grade - 1);
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    valid_grade(this->_grade + 1);
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
    return os;
}