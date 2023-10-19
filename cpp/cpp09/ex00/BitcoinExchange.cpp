/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/19 13:19:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *argv) {
	std::ifstream argvFile(argv);
	if (!argvFile.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(argvFile, line)) {
		std::cout << line << std::endl;
	}
	argvFile.close();

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

std::map<std::string, float>	BitcoinExchange::getData(std::string) {

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << it->first << " => " << it->second << '\n';

	}
	return (_data);
}

int		BitcoinExchange::validDate(std::string date) {
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	std::cout << year << month << day << std::endl;
	return (0);
}

void	BitcoinExchange::evalData(std::map<std::string, float>) {

}