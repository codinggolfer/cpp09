#include "RPN.hpp"

int main(int ac, char** av)  {
    if (ac == 2) {
        RPN laskin;
        laskin.calculate(av[1]);
    }
    else 
        std::cerr << "invalid amount of arguments\n";
    return (0);
}