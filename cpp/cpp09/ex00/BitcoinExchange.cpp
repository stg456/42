/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/21 17:06:34 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream infile(filename.c_str()); // c_str() converts string to char* with '\0'
	if (!infile.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::string date = line.substr(0, 10);
		float price = atof(line.substr(11).c_str());
		if (!(iss >> date >> price)) {
			std::cout << "Error: could not read file" << std::endl;
			return ;
		}
		_data.insert (std::pair<std::string, float>(date, price));
	}
	infile.close();	
}

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


std::map<std::string, float>	BitcoinExchange::getData(char *argv) {

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << it->first << " => " << it->second << '\n';

	}
	return (_data);
}

// int		BitcoinExchange::validDate(std::string date) {
// 	std::string year = date.substr(0, 4);
// 	std::string month = date.substr(5, 2);
// 	std::string day = date.substr(8, 2);
// 	std::cout << year << month << day << std::endl;
// 	return (0);
// }

// int		BitcoinExchange::validData(std::string data) {
// 	std::string date = data.substr(0, 10);
// 	std::string price = data.substr(11, 6);
// 	std::cout << date << " " << price << std::endl;
// 	return (0);
// }

// void	BitcoinExchange::evalData(std::map<std::string, float>) {

// }