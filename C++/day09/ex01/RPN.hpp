#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>

class RPN
{
	private:

	RPN(void);
	std::stack<int> value_stack;

	public:

	int getResult();
    RPN(std::string& input);
    RPN(RPN const& toCopy);
    RPN const& operator=(RPN const& toAffect);
    ~RPN(void);
	void calculation(const char input);
	bool check_validity(const char input);
};


#endif