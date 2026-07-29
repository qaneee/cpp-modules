#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <exception>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> db;

		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, float& out) const;
		float getRate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& path);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange &operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		void processInput(const std::string& path) const;
};

