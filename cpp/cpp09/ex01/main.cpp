/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	RPN	rpn;
	// std::stack<std::string> rpn;
	if (ac != 2) {
		std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
		return 1;
	}
	else if (rpn.check(av[1])) {
		std::cout << "Error: invalid expression" << std::endl;
		return 1;
	}
	std::string str_rpn = av[1];
	std::cout << rpn.calculate(str_rpn) << std::endl;

	return 0;
}