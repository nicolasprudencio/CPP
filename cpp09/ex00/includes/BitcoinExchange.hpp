#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>

class BitcoinExchange {

	public:
		BitcoinExchange();
		~BitcoinExchange();

		static void calculatePrice(std::multimap<std::string, double> &dB, std::multimap<std::string, double> &inputFile);
	private:
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
	
};

#endif