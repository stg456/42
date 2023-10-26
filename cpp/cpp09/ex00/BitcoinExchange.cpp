/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/26 12:39:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(std::string filename) {}
// 	std::ifstream infile(filename.c_str()); // c_str() converts string to char* with '\0'
// 	if (!infile.is_open()) {
// 		std::cout << "Error: could not open file" << std::endl;
// 		return ;
// 	}
// 	std::string line;
// 	while (std::getline(infile, line)) {
// 		std::istringstream iss(line);
// 		std::string date = line.substr(0, 10);
// 		float price = std::stof(line.substr(11).c_str());
// 		if (!(iss >> date >> price)) {
// 			std::cout << "Error: could not read file" << std::endl;
// 			return ;
// 		}
// 		_data.insert (std::pair<std::string, float>(date, price));
// 		std::cout << "key: " << date << "value: " << price << std::endl;
// 	}
// 	infile.close();	
// }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange & BitcoinExchange::operator = (BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
	}
	return *this;
}


void	BitcoinExchange::getData(std::string filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}
	std::string str;
	int check = 0;

	while (getline(file, str)) {
		if (check != 0) {
			std::string date = str.substr(0, 10);
			float price = std::stof(str.substr(11).c_str());
			_data.insert (std::pair<std::string, float>(date, price));
		}
		check++;
	}

	// for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
	// 	std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// }
	file.close();
}

void	BitcoinExchange::getInput(std::string input) {
	std::ifstream file2(input);
	std::string str2;
	if (!file2.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}

	int check = 0;
	while (getline(file2, str2)) {
		if (check != 0) {
			std::string date = str2.substr(0, 10);
				float price = std::stof(str2.substr(12));
			if (str2.size() < 11) {
				std::cout << "Error: bad input => " << str2 << std::endl;
			}
			// else if (!price)
			// 	std::cout << "Error: bad input => " << str2 << std::endl;
			else if (price < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (price > 1000)
				std::cout << "Error: too large a number." << std::endl;
			
			_data.insert(std::make_pair(date, price));
			std::cout << "key: " << date << " value: " << price << std::endl;
			// else
		}


		check++;
	}

	// for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		// std::cout << "key: " << it->first << " value: " << it->second << std::endl;
		// validDate(it);
		// std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// }
	file2.close();
}


void BitcoinExchange::validDate(std::map<std::string, float>::iterator it) {

	std::string year = it->first.substr(0, 4);
	std::string month = it->first.substr(5, 2);
	std::string day = it->first.substr(8, 2);

	if ((year.length() != 4 || month.length() != 2 || day.length() != 2) || (year < "2009" || year > "2022")
		|| (month < "01" || month > "12") || (day < "01" || day > "31"))
		std::cout << "Error: bad input => " << it->first << std::endl;
	else if ((year == "2012" || year == "2016" || year == "2020") && (month == "02" && day > "29"))
		std::cout << "Error: bad input => " << it->first << std::endl;
	else if ((year != "2012" || year != "2016" || year != "2020") && (month == "02" && day > "28"))
		std::cout << "Error: bad input => " << it->first << std::endl;
	else if ((month == "04" && day > "30") || (month == "06" && day > "30") || (month == "09" && day > "30") || (month == "11" && day > "30"))
		std::cout << "Error: bad input => " << it->first << std::endl;
	else {
		std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	}
}
