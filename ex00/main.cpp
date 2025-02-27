#include "BitcoinExchange.hpp"
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av) {
    if (ac == 2) {
        BitcoinExchange exchange;
        exchange.parseWallet(av[1]);
    }
    else
        std::cout << "Invalid amount of arguments\n";
}