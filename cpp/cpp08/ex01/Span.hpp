/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:34:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/08 16:37:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	private:
		unsigned int		_size;
		unsigned int		_count;
		int*				_array;
	
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& copy);
		~Span();
		Span& operato = (const Span& rhs);
		
		void addNumber(int nb);
		void addNumber(int nb, unsigned int count);
		int shortestSpan();
		int longestSpan();
};

#endif