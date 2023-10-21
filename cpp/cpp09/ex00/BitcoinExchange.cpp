/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/21 16:33:57 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream();
	
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