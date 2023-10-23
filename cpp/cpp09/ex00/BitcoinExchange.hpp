/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:21 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/23 11:28:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BITCOINEXCHANGE_HPP
// # define BITCOINEXCHANGE_HPP
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange 
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange & operator = (BitcoinExchange const &rhs);

		std::map<std::string, float>	getData(char *argv);
		int								validDate(std::string date);
		void							exchange(std::string input);


	private:
		std::map<std::string, float>	_data;
};

// #endif