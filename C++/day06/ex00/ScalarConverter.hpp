#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <climits>
# include <cfloat>
# include <cerrno>

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &assign);
	public:
		static void convert(std::string arg);
		

		
};

#endif