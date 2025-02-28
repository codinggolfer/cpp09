#pragma once

#include <iostream>
#include <sstream>

template <typename T> int validRPN(T token) {
    if (token.length() >= 3 || (token.length() > 1 && token[0] != '-')) {
        std::cerr << "Error\n";
        return 10;
    }
    if (token[0] == '-' && token.length() > 1) {
        try
        {
            int tmp = std::stoi(token);
            if (tmp < -10) {
                std::cerr << "Error\n";
                return 10;
            }
            else
                return tmp;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error" << '\n';
            return 10;
        }
    }

    if (token == "+") return(11);
    else if (token == "-") return (12);
    else if (token == "*") return (13);
    else if (token == "/") return (14);
    try
    {
            return std::stoi(token);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << '\n';
        return (10);
    }
}

class RPN
{
private:
    std::stack<int> stack;
    RPN(const RPN& copy);
    RPN& operator=(const RPN& other);
public:
    RPN();
    
    void calculate(char*);
    void minus();
    void plus();
    void multiply();
    void divide();

    ~RPN();
};
