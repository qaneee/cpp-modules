#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> stack;

		bool isOperator(const std::string &token) const;
		int calcOperation(const std::string &op);

	public:
		RPN();
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		~RPN();

		int calcExpression(const std::string &expression);
};

#endif
