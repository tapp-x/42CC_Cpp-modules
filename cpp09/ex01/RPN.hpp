#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>

class RPN {
public:
    RPN();
    ~RPN();

    RPN(const RPN &copy);
    RPN& operator=(const RPN &other);

    double evaluate(const std::string& expression);

private:
    bool isOperator(const std::string& token);
    double performOperation(double a, double b, const std::string& op);
    bool isValidToken(const std::string& token);
};

#endif