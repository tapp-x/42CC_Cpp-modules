#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
	loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) 
{
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);

	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: wrong database format.");    

	while (std::getline(file, line)) 
	{
		std::istringstream ss(line);
		std::string date;
		double rate;
		if (std::getline(ss, date, ',') && ss >> rate) 
		{
			if (!isValidDate(date))
				throw std::runtime_error("Error: wrong database format.");
			exchangeRates[date] = rate;
		} 
		else
			throw std::runtime_error("Error: wrong database format.");
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string year_str = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);

	struct tm timeinfo;
	memset(&timeinfo, 0, sizeof(struct tm));

	int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;

	if (mktime(&timeinfo) == -1) {
		return (false);
	}
	if (timeinfo.tm_year == year - 1900 &&
			timeinfo.tm_mon == month - 1 &&
			timeinfo.tm_mday == day)
		return (true);
	return (false);
}

double BitcoinExchange::getBitcoinValue(const std::string& date, double amount) const {
	std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

	if (it == exchangeRates.end() || (it != exchangeRates.begin() && it->first != date))
		--it;
	if (it == exchangeRates.end())
		throw std::runtime_error("Error: date not found.");
	return (amount * it->second);
}

