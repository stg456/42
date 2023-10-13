/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/13 15:12:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main() {
	Span sp = Span(5);

	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(21);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	// Span sp2 = Span(10000);
	// std::vector<int> v;
	// try {
	// 	for (int i = 0; i < 10000; i++)
	// 		v.push_back(i);
	// 	sp2.addNumbers(v.begin(), v.end());
	// 	std::cout << sp2.shortestSpan() << std::endl;
	// 	std::cout << sp2.longestSpan() << std::endl;
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// sp2.addNumbers(v.begin(), v.end());

	// std::cout << sp2.shortestSpan() << std::endl;
	// std::cout << sp2.longestSpan() << std::endl;

	return 0;
}