#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <ctime>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string& dbFile);
	~BitcoinExchange();

	double getBitcoinValue(const std::string& date, double amount) const;
	bool isValidDate(const std::string& date) const;

private:
	std::map<std::string, double> exchangeRates;

	void loadDatabase(const std::string& dbFile);
};

#endif
