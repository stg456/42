/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:11:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 13:13:13 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	*this = copy;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & rhs) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}


void	ToInt(double nb) {

}

void	ToFloat(double nb) {

}

void	ToDouble(double nb) {

}

void	ToChar(double nb) {

}

void	ft_convert(double nb) {
	ToInt(nb);
	ToFloat(nb);
	ToDouble(nb);
	ToChar(nb);
}