/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/17 14:08:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	BitcoinExchange btc;



	// try {
	// 	// BitcoinExchange exchange(argv[1]);
	// 	btc.getData();
	// }
	// catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	return 0;
}