# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *argv) {
	std::ifstream	input;
	std::ifstream	data;

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator = (BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->dataMap = rhs.dataMap;
	}
	return *this;
}

void	getData() {
	for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
		std::cout << it->first << " => " << it->second << '\n';
	}
}

const char* BitcoinExchange::notCorrectValueException::what() const throw() {
	return "Not correct value";
}
