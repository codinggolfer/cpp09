#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
    stack = copy.stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}

void RPN::multiply() {
    try {
        int b = stack.top(); stack.pop();
        int a = stack.top(); stack.pop();
        stack.push(a * b);
    }
    catch(...)
    {
        std::cerr << "Error\n";
    }
}

void RPN::plus() {
    try {
        int b = stack.top(); stack.pop();
        int a = stack.top(); stack.pop();
        stack.push(a + b);
    }
    catch(...)
    {
        std::cerr << "Error\n";
    }
}

void RPN::minus() {
    try {
        int b = stack.top(); stack.pop();
        int a = stack.top(); stack.pop();
        stack.push(a - b);
    }
    catch(...)
    {
        std::cerr << "Error\n";
    }
}

void RPN::divide() {
    try {
        int b = stack.top(); stack.pop();
        int a = stack.top(); stack.pop();
        stack.push(a / b);
    }
    catch(...)
    {
        std::cerr << "Error\n";
    }
}

void RPN::calculate(char* formula) {
    std::istringstream str(formula);
    int number;
    std::string token;

    while (str >> token)
    {
        number = validRPN(token);
        switch (number)
        {
            case 10:
                return;
            case 11:
                plus();
                break; 
            case 12:
                minus();
                break;
            case 13:
                multiply();
                break;
            case 14:
                divide();
                break;
            default:
                stack.push(number);  
                break;
        }
    }
    std::cout << stack.top() << std::endl;
}

RPN::~RPN() {}