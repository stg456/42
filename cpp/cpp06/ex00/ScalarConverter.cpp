/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:45:26 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/04 10:56:10 by stgerard         ###   ########.fr       */
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


int ScalarConverter::check(char *argv)
{
	if (strcmp(argv, "-inff") == 0 || strcmp(argv, "+inff") == 0 || strcmp(argv, "nanf") == 0 
		|| strcmp(argv, "-inf") == 0 || strcmp(argv, "+inf") == 0 || strcmp(argv, "nan") == 0
			|| strcmp(argv, "inf") == 0 || strcmp(argv, "inff") == 0)
		return (0);
	return (1);	
}

void	ScalarConverter::toChar(double d) {
	if (d >= 32 && d <= 126)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::toInt(double d) {
	if (d > std::numeric_limits<int>::min() && d < std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::toFloat(double d) {
    if (std::abs(d) > std::numeric_limits<float>::min() && std::abs(d) < std::numeric_limits<float>::max()) {
        float   f = static_cast<float>(d);
        int     i = static_cast<int>(d);

        std::cout << "float: " << static_cast<float>(d);
        if (f - i == 0)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
        std::cout << "float: out of range" << std::endl;
}

void	ScalarConverter::toDouble(double d) {
	if (std::abs(d) > std::numeric_limits<double>::min() && std::abs(d) < std::numeric_limits<double>::max()) {
		int     i = static_cast<int>(d);
		std::cout << "double: " << static_cast<double>(d);
		if (d - i == 0)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
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