#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

// BitcoinExchange.hpp

# include <iostream>

class BitcoinExchange 
{
	public:
		BitcoinExchange(char *argv);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange & operator = (BitcoinExchange const &rhs);

		void	getData();

	private:
		std::ifstream	data;
		std::ifstream	input;
}

#endif