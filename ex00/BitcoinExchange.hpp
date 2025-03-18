#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <sstream>
#include <chrono>
#include <algorithm>


template <typename T> void printBadInput(T date) {
    std::cout << "Error: bad input => " << date << std::endl;
}

template <typename T> void printInvalidNumber(T amount) {
    if (amount > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else if (amount < 0)
        std::cout << "Error: not a positive number." << std::endl;
}

template <typename T> double multiply(T x, T y) {
    return x * y;
}

template <typename T> void printValidInput(T map, std::string date, double amount) {
    auto it = map.find(date);

    if (it != map.end()) {
        std::cout << date << " => " << amount << " = " << multiply(amount, it->second) << std::endl;
        return ;
    }
    else {
        auto lower = map.lower_bound(date);
        auto higher = map.upper_bound(date);

        
        if (lower == map.begin())
            std::cout << "Error: nothing earlier found" << std::endl;
        else if (higher == map.end())
            std::cout << "Error: date out of range" << std::endl;
        else {
            --lower;
            std::cout << date << " => " << amount << " = " << multiply(amount, lower->second) << std::endl;
        }
    }
}


class BitcoinExchange
{
    private:
        std::map<std::string, double> _exchangeRate;
		bool validCsv = true;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();
        
        void parseWallet(char* wallet);
        void readCsv();
};


