/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 12:47:19 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	PmergeMe p;

	if (ac < 2) {
		std::cout << "Error: arguments required" << std::endl;
		return 1;
	}
	// std::cout << "a" << std::endl;
	for (int i = 1; i < ac; i++) {
		if ((p.check(av[i]))) {
			std::cout << "Error in arguments" << std::endl;
			return 1;
		}
	}
	// std::cout << "b" << std::endl;
	p.insert(av);
	std::cout << "c" << std::endl;
	p.print(ac, av);
	std::cout << "d" << std::endl;

	return 0;
}