#include "PmergeMe.hpp"

int main(int ac, char** av) {
	if (ac > 2) {
		try
		{
			PmergeMe merger(av);
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
		std::cerr << "Error: not enough arguments\n";
	return 0;
}