/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:16:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 14:16:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

// RPN & RPN::operator = (RPN const &rhs) {
// 	if (this != &rhs) {
// 		this->_stack = rhs._stack;
// 	}
// 	return *this;
// }

int	check(std::string av) {
	for (int i = 0; i < av.length(); i++) {
		if (av[i] == ' ')
			continue ;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/' || av[i] == '%')
			continue ;
		else if (av[i] >= '0' && av[i] <= '9')
			continue ;
		else
			return 1;
	}
	return 0;
}

int	RPN::calculate(std::string input) {
	int		nb1;
	int 	nb2;
	for (int i = 0; i < input.length(); i++) {
		
	}
	std::cout << input << std::endl;
	return 0;
}