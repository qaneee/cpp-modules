#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: couldn't open database file");

	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t sep = line.find(',');
		if (sep == std::string::npos)
			continue;

		std::string date = line.substr(0, sep);
		std::string rateStr = line.substr(sep + 1);
		db[date] = static_cast<float>(std::atof(rateStr.c_str()));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : db(obj.db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		db = obj.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static void trim(std::string &s)
{
	size_t start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;

	size_t end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		--end;

	s = s.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	static const int daysInMonth[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDay = 29;

	if (day < 1 || day > maxDay)
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &out) const
{
	std::istringstream ss(valueStr);
	float val;

	ss >> val;
	if (ss.fail() || !ss.eof())
		return false;

	out = val;
	return true;
}

float BitcoinExchange::getRate(const std::string &date) const
{
	if (db.empty())
		throw std::runtime_error("Error: no exchange rate available");

	std::map<std::string, float>::const_iterator it = db.lower_bound(date);

	if (it == db.begin() && it->first != date)
		throw std::runtime_error("Error: no exchange rate available for this date");

	if (it == db.end() || it->first != date)
		--it;

	return it->second;
}

void BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream file(path.c_str());
	std::string line;

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 1);

		trim(date);
		trim(valueStr);

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			float rate = getRate(date);
			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
