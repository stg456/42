/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:30 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 16:14:22 by stgerard         ###   ########.fr       */
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
	while (1) {
		getline(file2, str2);
		if (str2.size() == 0)
			break;
		if (check != 0) {
			int pos = str2.find("|");
			if (pos == -1) {
				std::cout << "Error: bad input => " << str2 << std::endl;
				break;
			}
			std::string str3 = str2.substr(pos + 2);
			std::string str4 = str3.substr(0, pos - 1);

			float value = std::atof(str4.c_str());
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (pos == -1)
				std::cout << "Error: bad input => " << str2 << std::endl;
			else {
				std::cout << "key: " << str2.substr(0, 10) << std::fixed << std::setprecision(2) << " value: " << value * getPrice(str3) << std::endl;
			}
			check++;
			// std::string date = str2.substr(0, 10);
			// 	float price = std::stof(str2.substr(12));
			// if (str2.size() < 11) {
			// 	std::cout << "Error: bad input => " << str2 << std::endl;
			// }
			// // else if (!price)
			// // 	std::cout << "Error: bad input => " << str2 << std::endl;
			// if (price < 0)
			// 	std::cout << "Error: not a positive number." << std::endl;
			// else if (price > 1000)
			// 	std::cout << "Error: too large a number." << std::endl;
			
			// _data.insert(std::make_pair(date, price));
			// std::cout << "key: " << date << " value: " << price << std::endl;
			// else
		}
		// check++;
	}

	// for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		// std::cout << "key: " << it->first << " value: " << it->second << std::endl;
		// validDate(it);
		// std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// }
	file2.close();
}


int BitcoinExchange::validDate(std::map<std::string, float>::iterator it) {

	std::string year = it->first.substr(0, 4);
	std::string month = it->first.substr(5, 2);
	std::string day = it->first.substr(8, 2);

	float y = std::stof(year.c_str());
	float m = std::stof(month.c_str());
	float d = std::stof(day.c_str());

	if (y < 2009 || y > 2022)
		return (-1);
	if (m < 1 || m > 12)
		return (-1);
	if (d < 1 || d > 31)
		return (-1);
	if ((y == 2012 || y == 2016 || y == 2020) && (m == 2 && d > 29))
		return (-1);
	if ((y != 2012 || y != 2016 || y != 2020) && (m == 2 && d > 28))
		return (-1);
	if ((m == 4 && d > 30) || (m == 6 && d > 30) || (m == 9 && d > 30) || (m == 11 && d > 30))
		return (-1);
	return 0;

	// if ((year.length() != 4 || month.length() != 2 || day.length() != 2) || (year < "2009" || year > "2022")
	// 	|| (month < "01" || month > "12") || (day < "01" || day > "31"))
	// 	std::cout << "Error: bad input => " << it->first << std::endl;
	// else if ((year == "2012" || year == "2016" || year == "2020") && (month == "02" && day > "29"))
	// 	std::cout << "Error: bad input => " << it->first << std::endl;
	// else if ((year != "2012" || year != "2016" || year != "2020") && (month == "02" && day > "28"))
	// 	std::cout << "Error: bad input => " << it->first << std::endl;
	// else if ((month == "04" && day > "30") || (month == "06" && day > "30") || (month == "09" && day > "30") || (month == "11" && day > "30"))
	// 	std::cout << "Error: bad input => " << it->first << std::endl;
	// else {
	// 	std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// }
}

float	BitcoinExchange::getPrice(std::string date) {
	std::map<std::string, float>::iterator it;

	std::string year = it->first.substr(0, 4);
	std::string month = it->first.substr(5, 2);
	std::string day = it->first.substr(8, 2);

	for (it = _data.begin(); it != _data.end(); it++) {
		if (date == it->first)
			return (it->second);
	}

	for (it = _data.begin(); it != _data.end(); it++) {
		if (year == it->first.substr(0, 4) && month == it->first.substr(5, 2)) {
			int date1 = std::stoi(it->first.substr(8, 2));
			int date2 = std::stoi(day);
			if (date1 > date2) {
				it--;
				return (it->second);
			}
		}
	}
	return 0;
}
