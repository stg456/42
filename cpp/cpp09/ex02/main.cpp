/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 18:01:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	PmergeMe p;

	if (ac < 2) {
		std::cout << "Error: arguments required" << std::endl;
		return 1;
	}

	for (int i; av[i]; i++) {
		if ((p.check(av[i]))) {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	p.insert(av);
	p.print(ac);

	return 0;
}