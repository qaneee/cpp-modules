#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {return *this;}
ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf"
	|| s == "+inf" || s == "+inff"
	|| s == "-inf" || s == "-inff"
	|| s == "inf" || s == "inff");
}

static bool isSpecialChar(const std::string &s)
{
	return (s.size() == 1
		&& std::isprint(static_cast<unsigned char>(s[0]))
		&& !std::isdigit(static_cast<unsigned char>(s[0]))
		&& s[0] != '.');
}

static bool hasLeadingOrTrailingSpace(const std::string &s)
{
	if (s.empty())
		return false;
	return (std::isspace(static_cast<unsigned char>(s[0]))
		|| std::isspace(static_cast<unsigned char>(s[s.size() - 1])));
}

static bool endsWithF(const std::string &s)
{
	return (s.size() > 1 && s[s.size() - 1] == 'f');
}

static std::string removeLast(const std::string &s)
{
	return s.substr(0, s.size() - 1);
}

static bool isValidNumber(const std::string &s)
{
	if (s.empty())
		return false;

	char *end = NULL;
	double value = std::strtod(s.c_str(), &end);

	if (end == s.c_str() || *end != '\0')
		return false;

	if (std::isnan(value) || std::isinf(value))
		return false;

	return true;
}

static void printChar(double d)
{
	std::cout << "char: ";

	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
	{
		std::cout << "impossible";
	}
	else
	{
		char c = static_cast<char>(d);

		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "'" << c << "'";
		else
			std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

static void printInt(double d)
{
	std::cout << "int: ";

	if (std::isnan(d) || std::isinf(d)
		|| d < INT_MIN || d > INT_MAX)
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << static_cast<int>(d);
	}
	std::cout << std::endl;
}

static void printFloat(double d)
{
	std::cout << "float: ";

	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << static_cast<float>(d) << "f";
	}
	else if (d > std::numeric_limits<float>::max()
		|| d < -std::numeric_limits<float>::max())
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << std::fixed
			<< std::setprecision(6)
			<< static_cast<float>(d)
			<< "f";
	}
	std::cout << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: "
	<< std::fixed
	<< std::setprecision(6)
	<< d
	<< std::endl;
}

static void printAll(double d)
{
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

static double getValue(const std::string &s)
{
	if (s == "nan" || s == "nanf")
		return std::numeric_limits<double>::quiet_NaN();

	if (s == "inf" || s == "+inf"
		|| s == "inff" || s == "+inff")
	{
		return std::numeric_limits<double>::infinity();
	}
	if (s == "-inf" || s == "-inff")
		return -std::numeric_limits<double>::infinity();

	return std::strtod(s.c_str(), NULL);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty() || hasLeadingOrTrailingSpace(literal))
	{
		std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible"
		<< std::endl;
		return;
	}

	if (isPseudo(literal))
	{
		printAll(getValue(literal));
		return;
	}

	if (isSpecialChar(literal))
	{
		printAll(static_cast<double>(literal[0]));
		return;
	}

	std::string numStr = literal;

	if (endsWithF(literal))
		numStr = removeLast(literal);

	if (!isValidNumber(numStr))
	{
		std::cout << "char: impossible\n"
			<< "int: impossible\n"
			<< "float: impossible\n"
			<< "double: impossible"
			<< std::endl;
		return;
	}
	printAll(getValue(numStr));
}