/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:06:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 13:34:43 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & copy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter & rhs);

		void	convert(double d);
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif