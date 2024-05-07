#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

static int checkSign(std::string value)
{
	if (value.compare("nan") == 0 || value.compare("nanf") == 0)
		return (2);
	else if (value.compare("+inf") == 0)
		return (3);
	else if (value.compare("-inf") == 0)
		return (4);
	return (0);
}

static bool isWholeNumber(std::string value)
{
	size_t pos;
	const char *str;

	pos = value.find('.');
	if (pos == std::string::npos)
		return (true);
	else
	{
		str = value.c_str();
		while (*(++str + pos) != '\0')
		{
			if (*(str + pos) != '0' && *(str + pos) != 'f')
				return (false);
		}
	}
	return (true);
}

static void convertToChar(double number, int sign)
{
	std::cout << "char: ";
	if (number  < 0 || number  > 127 || sign > 1)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if ((number  >= 0 && number  <= 31) || number  == 127)
			std::cout << "Non displayable";
	else
			std::cout << "'" << static_cast<char>(number) << "'";
	std::cout << std::endl;
}

 static void convertToDouble(double number, int sign)
 {
	std::cout << "double: ";
	if (number == HUGE_VAL)
		std::cout << "impossible";
	else if(sign == 2)
		std::cout << "nan";
	else if (sign == 3)
		std::cout << "+inf";
	else if (sign == 4)
		std::cout << "-inf";
	else
	{
		std::cout << static_cast<double>(number);
		if (sign == 1 && number < 1000000 && number > 1000000)
			std::cout << ".0";
	}
	std::cout << std::endl;

 }

 static void convertToInt(double number, int symbol)
{
	std::cout << "int: ";
	if (number < INT_MIN || number > INT_MAX || symbol > 1)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(number);
	std::cout << std::endl;
}

static void convertToFloat(double number, int symbol)
{
	std::cout << "float: ";
	if (number < -FLT_MAX || number > FLT_MAX)
		std::cout << "impossible";
	else if(symbol == 2)
		std::cout << "nanf";
	else if (symbol == 3)
		std::cout << "+inff";
	else if (symbol == 4)
		std::cout << "-inff";
	else
	{
		std::cout << static_cast<float>(number);
		if (symbol == 1 && number < 1000000 && number > 1000000)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;
}


void ScalarConverter::convert(std::string const number)
{
	double test;
	int sign;
	
	test = strtod(number.c_str(), 0);
	if (errno == ERANGE)
		test = HUGE_VAL;
	sign = checkSign(number);
	if (!sign)
	{
		if(test == HUGE_VAL)
			std::cout << "Impossible" << std::endl;
		if (isWholeNumber(number))
		 	sign = 1;
	}
	convertToChar(test, sign);
	convertToDouble(test, sign);
	convertToFloat(test, sign);
	convertToInt(test, sign);

}