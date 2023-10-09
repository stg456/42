/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:34:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/09 11:21:29 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>

class Span
{
	private:
		unsigned int		_size;
	
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& copy);
		~Span();
		Span& operator = (const Span& rhs);
		
		void addNumber(int nb);
		void addNumber(int nb, unsigned int count);
		int shortestSpan();
		int longestSpan();

		class noSpanPossible : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif