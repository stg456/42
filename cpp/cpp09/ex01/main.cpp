/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/26 14:38:33 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	RPN	rpn;
	// stack<std::string> rpn;
	while (ac) {
		rpn.push(av[ac - 1]);
		
		rpn = av[1];
		std::cout << rpn << std::endl;
		ac--;
	}

	std::cout << rpn.calculate() << std::endl;

	return 0;
}