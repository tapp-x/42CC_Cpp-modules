#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool isValidValue(const std::string& value) 
{
	std::istringstream ss(value);
	double num;
	ss >> num;

	if (ss.fail() || !ss.eof())
		return (false);
	if (num < 0 || num > 1000)
		return (false);
	return (true);
}

int main(int argc, char* argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << "Wrong args number" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc("data.csv");
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open()) 
		{
			std::cerr << "Error: could not open file." << std::endl;
			return (1);
		}

		std::string line;
		std::getline(inputFile, line);
		if (line.compare("date | value"))
			throw std::runtime_error("Error: bad input format");
		
		while (std::getline(inputFile, line)) 
		{
			std::istringstream str_s(line);
			std::string date, value;
			if (std::getline(str_s, date, '|') && std::getline(str_s, value)) 
			{
				try {
					if (date.empty() || value.empty())
						throw std::runtime_error("Error: empty date or value");
					date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
					value = value.substr(value.find_first_not_of(" \t\n\r\f\v"));
					if (!btc.isValidDate(date))
						throw std::runtime_error("Error: invalid date format");

					std::istringstream valueStream(value);
					double amount;
					valueStream >> amount;
					if (valueStream.fail() || !valueStream.eof() || amount < 0 || amount > 1000)
						throw std::runtime_error("Error: invalid value");

					double btcValue = btc.getBitcoinValue(date, amount);
					std::cout << date << " => " << amount << " = " << btcValue << std::endl;
				} catch (const std::exception& e) {
					std::cerr << e.what() << " => " << line << std::endl;
				}
			} 
			else
				std::cerr << "Error: bad input => " << line << std::endl;
		}
		inputFile.close();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
