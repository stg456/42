/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/18 11:38:09 by stgerard         ###   ########.fr       */
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
		this->dataMap = rhs.dataMap;
	}
	return *this;
}

void	getData() {

	for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
		std::cout << it->first << " => " << it->second << '\n';
	}
}

void	evalData(std::map) {

}