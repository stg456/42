#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

// BitcoinExchange.hpp

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange 
{
	public:
		BitcoinExchange(char *argv);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange & operator = (BitcoinExchange const &rhs);

		void	getData();

	private:
		std::string	data;
		std::string	input;
};

#endif