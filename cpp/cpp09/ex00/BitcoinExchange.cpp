/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/18 17:19:56 by stgerard         ###   ########.fr       */
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
		this->_map = rhs._map;
	}
	return *this;
}

std::map<std::string, float>	BitcoinExchange::getData() {
	return (_map);
	// for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++) {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }
}

int	validDate() {
	
}

void	evalData(std::map) {

}