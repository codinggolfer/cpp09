#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	
}

PmergeMe::PmergeMe(char** args) {
	validateStr(args);
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
    vec = copy.vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->vec = other.vec;
    }
    return *this;
}

bool isAllNumbers(const char* str) {
    if (str == nullptr) 
		return false;
    while (*str != '\0') {
        if (!std::isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

void PmergeMe::fillVector(char** args) {
	for (int i = 1; args[i]; i++) {
		try
		{
			int tmp = std::stoi(args[i]);
			if (tmp < 1)
				throw std::out_of_range("Error: input too small");
			vec.push_back(tmp);
			cue.push_back(tmp);
		}
		catch(const std::exception& e)
		{
			throw std::invalid_argument(e.what());
		}
		
	}
	::printContainer(vec, BEFORE);
	::printContainer(cue, BEFORE);
}

void PmergeMe::validateStr(char** args) {
	std::string ws(" \n\t\v\f\r\b");
	for (int i = 1; args[i]; i++) {
		std::string tmp(args[i]);
		if (ws.contains(tmp) || !isAllNumbers(args[i]))
			throw std::invalid_argument("Error: invalid input");
	}
	fillVector(args);
}



PmergeMe::~PmergeMe() {
	vec.clear();
	cue.clear();
}