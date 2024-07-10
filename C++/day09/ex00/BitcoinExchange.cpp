#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	try
	{
		_setTable();
	}
	catch (std::exception &e)
	{
		std::string error = e.what();
		std::cout << error;
	}
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::_setTable(void)
{
	std::string path = "data.csv";
	std::ifstream data_db(path.c_str());
	if (!data_db.is_open())
		throw(std::runtime_error("invalid file"));
	std::stringstream dbstream;
	dbstream << data_db.rdbuf();
	createMap(dbstream);
	showMap();
}

void BitcoinExchange::showMap()
{
	for (std::map<time_t, float>::iterator it = _btcexchangeRate.begin(); it != _btcexchangeRate.end();)
	{
		// std::cout << "time = " << it->first	<< " value = " << it->second << std::endl;
		++it;
	}
}

bool operator!=(struct tm const &lhs, struct tm const &rhs)
{
	if (lhs.tm_year != rhs.tm_year)
	{
		// std::cout << lhs.tm_year << " et annee " << rhs.tm_year << std::endl;
		return (true);
	}
	if (lhs.tm_mon != rhs.tm_mon)
	{
		// std::cout << lhs.tm_mon << " et annee " << rhs.tm_mon << std::endl;
		return (true);
	}
	if (lhs.tm_mday != rhs.tm_mday)
	{
		// std::cout << lhs.tm_mday << " et annee " << rhs.tm_mday << std::endl;
		return (true);
	}
	return (false);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src)
{
	this->_btcexchangeRate = src._btcexchangeRate;
	return (*this);
}

void BitcoinExchange::createMap(std::stringstream &dbstream)
{
	std::string buff;
	getline(dbstream, buff);
	std::stringstream line(buff);
	std::string key;
	std::string value;
	while (getline(dbstream, buff))
	{
		std::stringstream line(buff);
		std::getline(line, key, ',');
		std::getline(line, value, '\n');
		_btcexchangeRate.insert(std::pair<time_t, float>(getKey(key), getValue(value)));
	}
}
void BitcoinExchange::retrieveValue(std::string path)
{
	std::ifstream data_db(path.c_str());
	if (!data_db.is_open())
		throw(std::runtime_error("invalid file\n"));
	std::stringstream dbstream;
	dbstream << data_db.rdbuf();
	std::string buff;
	getline(dbstream, buff);
	std::stringstream line(buff);
	std::string key;
	std::string value;
	time_t tt_value;
	while (getline(dbstream, buff))
	{
		try
		{
		std::stringstream line(buff);
		std::getline(line, key, '|');
		std::getline(line, value, '\n');
		// std::string test = "2011-01-03";
		tt_value = getKey(key);
		getValue(value);
		struct tm *tm;
		bzero(&tm, sizeof(tm));
		tm = localtime(&tt_value);
		// std::cout << "key = " << tt_value << std::endl;
		// std::cout << "atol = " << atol(value.c_str()) << std::endl;
		// std::cout << "year = " << tm->tm_year << "-" << tm->tm_mon << "-" << tm->tm_mday << std::endl;
		std::cout << key << " => " << value << " = " << atof(value.c_str()) * btcConverter(*tm) << std::endl;
		}
		catch (std::exception &e)
		{
		std::string error = e.what();
		std::cout << error << std::endl;
		}
	}
}

double BitcoinExchange::getValue(std::string &value)
{
	double d_value;
	std::stringstream ss_stream(value);
	ss_stream >> d_value;

	if (d_value < 0)
	{
		throw(std::out_of_range("Error not a positive number:" + value));
	}
	else if (d_value > std::numeric_limits<int>::max())
	{
		throw(std::out_of_range("Error too large a number:" + value));
	}
	return (d_value);
}

time_t BitcoinExchange::getKey(std::string &s_key)
{
	struct tm tm;
	bzero(&tm, sizeof(tm));

	std::stringstream ss_key;
	ss_key << s_key;
	std::string date;
	std::getline(ss_key, date, '-');
	tm.tm_year = std::atoi(date.c_str()) - 1900;
	// std::cout <<  "annee = " << tm.tm_year << std::endl;
	std::getline(ss_key, date, '-');
	tm.tm_mon = std::atoi(date.c_str()) - 1;
	// std::cout <<  "mois = " << tm.tm_mon<< std::endl;
	std::getline(ss_key, date, '-');
	tm.tm_mday = std::atoi(date.c_str());
	// std::cout <<  "jour = " << tm.tm_mday << std::endl;
	struct tm copy;
	bzero(&copy, sizeof(copy));
	copy.tm_year = tm.tm_year;
	copy.tm_mon = tm.tm_mon;
	copy.tm_mday = tm.tm_mday;
	time_t key = mktime(&tm);
	// std::cout << key << std::endl;
	if (key == -1 || copy != tm)
	{
		// std::cout << "key = |" << s_key << "|" << std::endl;
		throw(std::out_of_range("Error: bad input => " + s_key));
	}
	return (key);
}

double BitcoinExchange::btcConverter(struct tm tm)
{
	struct tm copy;
	bzero(&copy, sizeof(copy));
	copy.tm_year = tm.tm_year;
	copy.tm_mon = tm.tm_mon;
	copy.tm_mday = tm.tm_mday;
	time_t date = mktime(&tm);
	// std::cout << date << std::endl;
	if (date == -1 || copy != tm)
		throw(std::out_of_range("Invalid data"));
	while (1)
	{
		for (std::map<time_t, float>::iterator it = _btcexchangeRate.begin(); it != _btcexchangeRate.end(); ++it)
		{
			// std::cout << "\ndate = " << date << " first  = " << it->first << " second = " << it->second << std::endl;
			if (it->first == date)
				return (it->second);
		}
		if (copy.tm_mday > 1)
			--copy.tm_mday;
		else if (copy.tm_mon > 0)
		{
			copy.tm_mday = 31;
			--copy.tm_mon;
		}
		else
		{
			copy.tm_mday = 31;
			copy.tm_mon = 11;
			--copy.tm_year;
		}
		// if (copy != tm)
		// {
		tm.tm_year = copy.tm_year;
		tm.tm_mon = copy.tm_mon;
		tm.tm_mday = copy.tm_mday;
		// std::cout << "year = " << tm.tm_year << "-" << tm.tm_mon << "-" << tm.tm_mday << std::endl;
		date = mktime(&tm);
		// }
	}
	return (-1);
}
