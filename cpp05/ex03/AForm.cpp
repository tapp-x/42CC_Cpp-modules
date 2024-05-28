/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:48:05 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 15:53:29 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _is_signed(false), _grade_to_sign(signGrade), _grade_to_exec(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed),
        _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_is_signed = other._is_signed;
    }
    return *this;
}

std::string AForm::get_name() const { 
    return (_name); 
}
bool AForm::is_signed() const {
    return (_is_signed); 
}

int AForm::get_sign_grade() const {
     return (_grade_to_sign); 
}

int AForm::get_exec_grade() const {
     return (_grade_to_exec); 
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.get_grade() > _grade_to_sign)
        throw GradeTooLowException();
    _is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.get_name() << ", requires grade " << form.get_sign_grade()
        << " to sign, grade " << form.get_exec_grade() << " to execute. Signed: " << (form.is_signed() ? "Yes" : "No");
    return out;
}
