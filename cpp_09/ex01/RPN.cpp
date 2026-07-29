#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& obj) : stack(obj.stack) {}

RPN& RPN::operator=(const RPN& obj)
{
	if (this != &obj)
		stack = obj.stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::calcOperation(const std::string &op)
{
	if (stack.size() < 2)
		throw std::runtime_error("Error: Stack Underflow");
	
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	switch (op[0])
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
				if (b == 0)
					throw std::runtime_error("Error: Division by 0");
				return a / b;
		default :
			throw std::runtime_error("Error: Invalid Operator");
	}
}

int RPN::calcExpression(const std::string &expression)
{
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (isOperator(token))
		{
			int res = calcOperation(token);
			stack.push(res);
		}
		else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		{
			stack.push(token[0] - '0');
		}
		else
			throw std::runtime_error("Error: Invalid Token");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid Expression");
	
	int res = stack.top();
	stack.pop();
	return res;
}