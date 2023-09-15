/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:11:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 12:55:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "convert.hpp"

Convert::Convert() {}

Convert::Convert(const Convert & copy) {
	*this = copy;
}

Convert & Convert::operator = (const Convert & rhs) {
	return *this;
}

Convert::~Convert() {}

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