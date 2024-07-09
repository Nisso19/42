#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

# include <cfloat>
# include <limits>
# include <exception>
# include <string.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <map>
# include <string>
# include <climits>

class BitcoinExchange
{
	private:
		void _setTable();
		std::map<time_t, float>_btcexchangeRate;

	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange & src );
		~BitcoinExchange( void );
		double getValue( std::string & value );
		time_t getKey(std::string& s_key);
		void showMap();
		double btcConverter(struct tm tm);
		struct tm  & operator=( struct tm const & lhs);
		// std::ifstream OpenFile(std::string path);
		BitcoinExchange & operator=( BitcoinExchange & src );
		void retrieveValue(std::string path);
		void createMap(std::stringstream& dbstream);
};
bool operator!=( struct tm const & lhs,  struct tm const & rhs );
#endif