/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 13:58:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	PmergeMe p;

	if (ac < 2) {
		std::cout << "Error: arguments required" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++) {
		if ((p.check(av[i]))) {
			std::cout << "Error in arguments" << std::endl;
			return 1;
		}
	}
	p.insert(av);
	p.print(ac, av);

	return 0;
}

// make re && ./PmergeMe  `jot -r 3000 1 100000 | tr '\n' ' '`