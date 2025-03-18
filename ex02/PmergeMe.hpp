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



template <typename T> void binaryInsert(T& container, int value) {
    auto pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

template <typename T> T MySort(T arr) {
    int n = arr.size();
    if (n <= 1) 
		return arr;

    std::vector<std::pair<int, int>> pairs;
    std::vector<int> leftover;


    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) 
			std::swap(arr[i], arr[i + 1]);
        pairs.push_back({arr[i], arr[i + 1]});
    }

    
    if (n % 2 != 0) 
		leftover.push_back(arr[n - 1]);

    
    T baseList;
    for (const auto& p : pairs) {
        baseList.push_back(p.first);
        leftover.push_back(p.second);
    }

    
    baseList = MySort(baseList);


   for (int value : leftover) {
        binaryInsert(baseList, value);
    }

    return baseList;
}

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
