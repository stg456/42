/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:45:26 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 14:24:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	*this = copy;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & rhs) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}



void	ScalarConverter::toChar(double d) {
	if (d >= 32 && d <= 126)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::toInt(double d) {
	int i = static_cast<int>(d);
}

void	ScalarConverter::toFloat(double d) {
	float f = static_cast<float>(d);
}

void	ScalarConverter::toDouble(double d) {
	return (d);
}

void	ScalarConverter::convert(double d) {
	ScalarConverter	sc;

	sc.toChar(d);
	sc.toInt(d);
	sc.toFloat(d);
	sc.toDouble(d);
}