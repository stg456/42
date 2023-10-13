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
		this->data = rhs.data;
		this->input = rhs.input;
	}
	return *this;
}

void	getData() {
	
}

