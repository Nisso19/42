#include "RPN.hpp"

RPN::RPN()
{

}


void RPN::calculation(const char input)
{
	int i;
	int j;
	i = value_stack.top();
	value_stack.pop();
	j = value_stack.top();
	value_stack.pop();
	std::cout << "i = " << i << "j = " << j << std::endl;
	if(input == '-')
		return(value_stack.push(j - i));
	else if(input == '+')
		return(value_stack.push(j + i));
	else if(input == '/')
		return(value_stack.push(j / i));
	else if(input == '*')
		return(value_stack.push(j * i));
}

bool RPN::check_validity(const char input)
{
	if (input == ' ')
		return 1;	
	if(input != '-' && input != '+' && input != '/' && input != '*')
	{
		std::cout << "input = " << input << std::endl; 
		return 0;
	}
	else if(value_stack.size() < 2)
	{
		std::cout << "teest2\n";
		return 0;
	}
	else
	{
		std::cout << "teest3\n";
		calculation(input);
		return 1;
	}
}

RPN::RPN(std::string& input)
{
	int i = -1;
	while(input[++i])
	{
		if(input.empty())
			throw(std::runtime_error("Empty string"));
		if(input[i] <= '9' && input[i] >= '0')
			value_stack.push(input[i] - '0');
		else if(check_validity(input.c_str()[i]) != 1)
		{
			throw(std::out_of_range("Invalid arguments"));
		}
	}
	if(value_stack.size() > 1)
		throw(std::out_of_range("Invalid arguments"));
}

RPN::RPN(RPN const& toCopy)
    : value_stack(toCopy.value_stack)
{

}

int RPN::getResult()
{
	return(value_stack.top());
}

RPN const& RPN::operator=(RPN const& toAffect)
{
    if (this != &toAffect)
    {
        value_stack = toAffect.value_stack;
    }
    return (*this);
}

RPN::~RPN(void)
{

}

