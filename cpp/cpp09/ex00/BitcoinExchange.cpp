# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *argv) {
	// std::ifstream	input;
	// std::ifstream	data;
	std::ifstream argvFile(argv);
	if (!argvFile.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(argvFile, line)) {
		std::cout << line << std::endl;
	}
	// input.open(argv[1]);
	// if (!input.is_open()) {
	// 	std::cout << "Error: file not found" << std::endl;
	// 	return ;
	// }
	// data.open("data.csv");
	// if (!data.is_open()) {
	// 	std::cout << "Error: file not found" << std::endl;
	// 	return ;
	// }
	// std::string line;
	// while (std::getline(data, line)) {
	// 	std::cout << line << std::endl;
	// }
	// std::string line;
	// while (std::getline(input, line)) {
	// 	std::cout << line << std::endl;
	// }
	// input.close();
	// data.close();
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
