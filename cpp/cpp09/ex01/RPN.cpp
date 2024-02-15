/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:16:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:06 by stgerard         ###   ########.fr       */
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

int	RPN::check(std::string av) {
	for (size_t i = 0; i < av.length(); i++) {
		if (av[i] == ' ')
			continue ;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/')
			continue ;
		else if (av[i] >= '0' && av[i] <= '9')
			continue ;
		else
			return 1;
	}
	return 0;
}

int	RPN::calculate(std::string str_rpn) {
	int		nb1;
	int 	nb2;
	for (size_t i = 0; i < str_rpn.length(); i++) {
		if (str_rpn[i] == ' ')
			continue ;
		else if (isdigit(str_rpn[i])) {
			nb1 = stoi(std::string(1, str_rpn[i]));
			_stack.push(nb1); // ajoute un element au dessus de la pile
		}
		else {
			nb2 = _stack.top(); // accede au 1er element
			_stack.pop(); // remove le 1er element
			if (_stack.empty()) {
				std::cout << "Error" << std::endl;
				return 1;
			}
			nb1 = _stack.top();
			_stack.pop();

			if (str_rpn[i] == '+')
				_stack.push(nb1 + nb2);
			else if (str_rpn[i] == '-')
				_stack.push(nb1 - nb2);
			else if (str_rpn[i] == '*')
				_stack.push(nb1 * nb2);
			else if (str_rpn[i] == '/')
				_stack.push(nb1 / nb2);
		}
	}
	return (_stack.top());
}