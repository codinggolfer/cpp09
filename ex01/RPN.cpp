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
		if (stack.empty())
			throw("");
        int b = stack.top(); stack.pop();
		if (stack.empty())
			throw("");
        int a = stack.top(); stack.pop();
        stack.push(a * b);
}

void RPN::plus() {
		if (stack.empty())
			throw("");
        int b = stack.top(); stack.pop();
		if (stack.empty())
			throw("");
        int a = stack.top(); stack.pop();
        stack.push(a + b);
}

void RPN::minus() {
		if (stack.empty())
			throw("");
        int b = stack.top(); stack.pop();
		if (stack.empty())
			throw("");
        int a = stack.top(); stack.pop();
        stack.push(a - b);
}

void RPN::divide() {
		if (stack.empty())
			throw("");
        int b = stack.top(); stack.pop();
		if (stack.empty())
			throw("");
        int a = stack.top(); stack.pop();
		if (a == 0 || b == 0)
			throw("");
        stack.push(a / b);
}

bool validateString(char* formula) {
	std::istringstream tmp(formula);
	std::string str;
	getline(tmp, str);

	if (!std::isdigit(str[0]))
		throw("");
	if (!tmp.eof())
		return false;

	int count = 0;
	int operatorCount = 0;
	

	for (char ch : str) {
		if (ch >= '0' && ch <= '9') {
			count++;
		}
		if (ch == '*' || ch == '-' || ch == '+' || ch == '/') {
			operatorCount++;
		}
	}

	if (count <= operatorCount)
		return false;
	return true;
}

void RPN::calculate(char* formula) {
    std::istringstream str(formula);
    int number;
    std::string token;

	if (!validateString(formula)) {
		throw ("");
	}
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