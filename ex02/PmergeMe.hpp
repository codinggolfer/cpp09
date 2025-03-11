#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <deque>
#include <chrono>

enum which {
	BEFORE,
	AFTER
};

template <typename T> void printContainer(T& container, int which) {
	switch (which)
	{
	case BEFORE:
		std::cout << "Before:";
		break;
	case AFTER:
		std::cout << "After:";
	default:
		break;
	}
	for (auto it = container.begin(); it != container.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> cue;


	PmergeMe& operator=(const PmergeMe& other);
	PmergeMe(const PmergeMe& copy);
	PmergeMe();
public:
	PmergeMe(char** args);
	~PmergeMe();

	void fillVector(char**);
	void validateStr(char**);

};
