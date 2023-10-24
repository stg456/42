/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/24 16:18:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN 
{
	public:
		RPN();
		~RPN();
		RPN(RPN const &src);

		RPN & operator = (RPN const &rhs);

		void	calculate(std::string input);

	private:
		std::stack<float>	_stack;
};