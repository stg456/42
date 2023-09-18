/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:45:26 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 10:06:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & rhs) {
	// if (this != &rhs)
	// {
	// }
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string str) {}

void	ScalarConverter::toChar() {}

void	ScalarConverter::toInt() {}

void	ScalarConverter::toFloat() {}

void	ScalarConverter::toDouble() {}
