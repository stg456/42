/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:16:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/26 14:42:46 by stgerard         ###   ########.fr       */
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

void	RPN::calculate(std::string input) {
	int		nb1;
	int 	nb2;
	for (int i = 0; i < input.length(); i++) {
		
	}
	std::cout << input << std::endl;
}