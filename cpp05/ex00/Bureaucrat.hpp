#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {

public:

	Bureaucrat(std::string name);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &x);

	Bureaucrat & operator=(Bureaucrat const &param);
    std::string get_name() const;

private:
        std::string const _name;
};

#endif