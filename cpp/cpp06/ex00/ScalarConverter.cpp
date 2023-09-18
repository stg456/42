/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:45:26 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 17:12:11 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	*this = copy;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & rhs) {
	if (this == &rhs)
		return *this;
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
	if (d > std::numeric_limits<int>::min() && d < std::numeric_limits<int>::max() && std::numeric_limits<int>::signaling_NaN())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	ScalarConverter::toFloat(double d) {
	if(!std::numeric_limits<float>::infinity())
		std::cout << "float: " << static_cast<float>(d) << std::endl;
	else
		std::cout << "float: out of range" << std::endl;
}

void	ScalarConverter::toDouble(double d) {
	if(!std::numeric_limits<double>::infinity())
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	else
		std::cout << "double: out of range" << std::endl;
}

void	ScalarConverter::convert(double d) {
	ScalarConverter	sc;

	sc.toChar(d);
	sc.toInt(d);
	sc.toFloat(d);
	sc.toDouble(d);
}