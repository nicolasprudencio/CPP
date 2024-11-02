#include "./includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::calculatePrice(std::multimap<std::string, double> &db, std::multimap<std::string, double> &inputFile) 
{
	std::multimap<std::string, double>::iterator date;

	for (std::multimap<std::string, double>::const_iterator it = inputFile.begin(); it != inputFile.end(); ++it)
	{
		date = db.lower_bound(it->first);
		if (date == db.end() || date->first > it->first)
		{
			if (date != db.begin())
				--date;
			else
				continue; 
		}
		std::cout << date->first << " => " << it->second << " " << it->second * date->second << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	(void)obj;
	return *this;
}

