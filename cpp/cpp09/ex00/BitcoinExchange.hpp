#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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

		// class notCorrectValueException : public std::exception {
		// 	virtual const char* what() const throw();
		// };

	private:
		std::map<std::string, float>	dataMap;
};

#endif