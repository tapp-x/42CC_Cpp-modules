#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
    std::cout << "Default constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for Democrat" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &x) {
    std::cout << "Copy constructor called for Bureaucrat" << std::endl;
    this->_name = x.get_name();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &param) {
    std::cout << "Assignation operator called for Bureaucrat" << std::endl;

}

std::string Bureaucrat::get_name() const {
    return (this->_name);
}