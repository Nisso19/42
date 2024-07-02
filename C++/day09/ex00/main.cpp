#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./btc inputFile.txt" << std::endl;
	(void) argv;
	BitcoinExchange();
	// BitcoinExchange btc(db);
	// std::string inF = argv[1];
	// btc.showRes(inF);
	// std::map<time_t, float> m = btc.getMap();
	return (0);
}