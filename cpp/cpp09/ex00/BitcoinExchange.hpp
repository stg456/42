/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:23:21 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/19 12:28:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange 
{
	public:
		BitcoinExchange();
		BitcoinExchange(char *argv);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange & operator = (BitcoinExchange const &rhs);

		std::map<std::string, float>	getData(std::string);
		int validDate(std::string date);

		void	evalData(std::map<std::string, float>);



	private:
		std::map<std::string, float>	_data;
};

#endif