/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:19:20 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 16:21:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {

public:

	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	
	Bureaucrat(Bureaucrat const &cpy);
	Bureaucrat & operator=(Bureaucrat const &param);

    std::string get_name() const;
	int get_grade() const;
	
	void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form);
    void executeForm(const AForm& form);

	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
        std::string const _name;
		int _grade;

		void valid_grade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif