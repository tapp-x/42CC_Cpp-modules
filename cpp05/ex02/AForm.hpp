/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:46:47 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 15:52:43 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string& name, int signGrade, int execGrade);
    virtual ~AForm();

    AForm(const AForm& copy);
    AForm& operator=(const AForm& other);

    std::string get_name() const;
    bool is_signed() const;
    int get_sign_grade() const;
    int get_exec_grade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char* what() const throw();
    };

private:
    const std::string   _name;
    bool                _is_signed;
    const int           _grade_to_sign;
    const int           _grade_to_exec;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
