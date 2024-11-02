#include "./includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool validDate(const std::string &dateStr, double value, bool isInputFile) {
	std::stringstream ss(dateStr);
	int year, month, day;
	char delim;

	if (!(ss >> year >> delim >> month >> delim >> day)) {
		std::cerr << "Error: invalid date format." << std::endl;
		return false;
	}

	if (year < 2009 || year > 2022) {
		std::cerr << "Error: year out of range. Valid range: 2009-2022." << std::endl;
		return false;
	}
	if (month < 1 || month > 12) {
		std::cerr << "Error: invalid month." << std::endl;
		return false;
	}
	if (day < 1 || day > 31 || (month == 2 && day > (isLeapYear(year) ? 29 : 28)) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		std::cerr << "Error: invalid day for the month." << std::endl;
		return false;
	}

	if ((value < 0 || value > 1000) && isInputFile) {
		std::cerr << "Error: invalid or missing exchange rate." << std::endl;
		return false;
	}

	return true;
}

std::multimap<std::string, double> loadDatabase(std::ifstream &db, char delimiter) {
	std::multimap<std::string, double> database;
	std::string line;

	getline(db, line);
	if (delimiter == '|' && line.compare("date | value") != 0) {
		throw std::invalid_argument("Invalid file format: " + line);
	}
	while (getline(db, line)) {
		std::string valueStr = line.substr(line.find(delimiter) + 1);
	
		std::stringstream ss(valueStr);
		double value = 0.0;
		ss >> value;

		if (validDate(line, value, delimiter == '|')) {
			std::string key = line.substr(0, line.find(delimiter));
			database.insert(std::make_pair(key, value));
		} else {
			std::cerr << "Invalid line: " << line << std::endl;
		}
	}
	return database;
}


int main(int argc, char **argv) {
	std::multimap<std::string, double> bitcoinDatabase;
	std::multimap<std::string, double> dateBitcoinIndexDatabase;

	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin [input file]" << std::endl;
		return 1;
	}
	
	try {
		std::ifstream inputFile(argv[1]);
		std::ifstream db("data.csv");

		bitcoinDatabase = loadDatabase(db, ',');
		dateBitcoinIndexDatabase = loadDatabase(inputFile, '|');
		BitcoinExchange::calculatePrice(bitcoinDatabase, dateBitcoinIndexDatabase);
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}