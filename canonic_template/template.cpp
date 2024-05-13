#include "template.hpp"

Ex::Ex() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Ex::~Ex() {
	std::cout << "Destructor called" << std::endl;
}

Ex::Ex(Ex const &x) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = x._value;
}

Ex & Ex::operator=(Ex const &param) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = param.value();

	return (*this);
}