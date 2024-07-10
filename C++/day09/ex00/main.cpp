#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return(std::cout << "Insert a file: ./BitcoinExchange file.txt " << std::endl , 0);
	(void) argv;
	BitcoinExchange btc;
	btc.retrieveValue(argv[1]);
	return (0);
}