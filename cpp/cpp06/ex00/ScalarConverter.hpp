/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:06:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 14:06:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & copy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter & rhs);

		void	convert(double d);
		void	toChar(double d);
		void	toInt(double d);
		void	toFloat(double d);
		void	toDouble(double d);
};

#endif