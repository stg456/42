/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:06:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 10:06:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & copy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter & rhs);

		void	convert(std::string str);
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif