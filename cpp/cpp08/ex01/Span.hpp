/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:34:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/10 17:20:43 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <ctime>
# include <cstdlib>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_v;
	
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& copy);
		~Span();
		Span& operator = (const Span& rhs);
		
		void addNumber(int nb);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class noAddPossibleException : public std::exception {
			virtual const char* what() const throw();
		};

		class noSpanPossibleException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif