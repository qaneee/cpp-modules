#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { return ((void)other, *this); }
ScalarConverter::~ScalarConverter() { }

static bool myIsNan(double d) { return d != d; }
static bool myIsInf(double d) { return d != 0.0 && d + d == d; }

static std::string trim(const std::string &s)
{
	size_t start = 0;
	size_t end = s.size();

	while (start < end && std::isspace(static_cast<unsigned char>(s[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;
	return s.substr(start, end - start);
}

static bool isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf" || s == "inf" || s == "inff"
		|| s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff");
}

static double pseudoValue(const std::string &s)
{
	if (s == "nan" || s == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (s == "-inf" || s == "-inff")
		return -std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::infinity();
}

static bool parseNumeric(const std::string &s, double &value)
{
	char *end = NULL;
	value = std::strtod(s.c_str(), &end);
	if (end == s.c_str() || *end != '\0')
		return false;
	return true;
}

static bool parseInt(const std::string &s, int &value)
{
	char *end = NULL;
	long parsed = std::strtol(s.c_str(), &end, 10);
	if (end == s.c_str() || *end != '\0')
		return false;
	if (parsed < INT_MIN || parsed > INT_MAX)
		return false;
	value = static_cast<int>(parsed);
	return true;
}

bool ScalarConverter::getChar(const std::string &lit, char &c)
{
	if (lit.size() != 1)
		return false;

	unsigned char uc = static_cast<unsigned char>(lit[0]);
	if (std::isdigit(uc) || lit[0] == '.' || !std::isprint(uc))
		return false;
	c = lit[0];
	return true;
}

bool ScalarConverter::getInt(const std::string &lit, int &i)
{
	return (!lit.empty() && parseInt(lit, i));
}

bool ScalarConverter::getFloat(const std::string &lit, double &d)
{
	if (lit.empty() || lit[lit.size() - 1] != 'f')
		return false;

	std::string body = lit.substr(0, lit.size() - 1);
	if (body.empty())
		return false;
	if (!parseNumeric(body, d))
		return false;
	if (myIsNan(d) || myIsInf(d))
		return false;
	return true;
}

bool ScalarConverter::getDouble(const std::string &lit, double &d)
{
	if (lit.empty())
		return false;
	if (!parseNumeric(lit, d))
		return false;
	if (myIsNan(d) || myIsInf(d))
		return false;
	return true;
}

static std::string trimmedFixed(double value, int precision)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << value;
	std::string s = oss.str();

	size_t dot = s.find('.');
	size_t last = s.find_last_not_of('0');
	if (last == std::string::npos)
		return s;
	if (last == dot)
		last++;
	s.erase(last + 1);
	return s;
}

static void printChar(double d)
{
	std::cout << "char: ";
	if (myIsNan(d) || myIsInf(d) || d < CHAR_MIN || d > CHAR_MAX)
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
	std::cout << "\n";
}

static void printInt(double d)
{
	std::cout << "int: ";
	if (myIsNan(d) || myIsInf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << "\n";
}

static void printFloat(double d)
{
	std::cout << "float: ";
	if (myIsNan(d) || myIsInf(d))
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
		std::cout << trimmedFixed(static_cast<float>(d), 9) << "f";
	}
	std::cout << "\n";
}

static void printDouble(double d)
{
	std::cout << "double: ";
	if (myIsNan(d) || myIsInf(d))
		std::cout << d;
	else
		std::cout << trimmedFixed(d, 9);
	std::cout << "\n";
}

static void printAll(double d)
{
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

static void printImpossible(void)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void ScalarConverter::convert(const std::string &literal)
{
	std::string lit = trim(literal);
	if (lit.empty())
	{
		return printImpossible();
	}
	if (isPseudo(lit))
	{
		printAll(pseudoValue(lit));
		return;
	}
	char c;
	if (getChar(lit, c))
	{
		printAll(static_cast<double>(static_cast<unsigned char>(c)));
		return;
	}
	double d;
	if (getFloat(lit, d))
	{
		printAll(d);
		return;
	}
	int i;
	if (getInt(lit, i))
	{
		printAll(static_cast<double>(i));
		return;
	}
	if (getDouble(lit, d))
	{
		printAll(d);
		return;
	}
	printImpossible();
}