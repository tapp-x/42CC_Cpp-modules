#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

class Ex {

public:

	Ex();
	~Ex();
	Ex(Ex& x);

	Ex & operator=(Ex const &param);

private:

	int	_value;
};

#endif