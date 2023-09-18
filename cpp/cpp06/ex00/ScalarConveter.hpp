/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:40:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 09:49:45 by stgerard         ###   ########.fr       */
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