/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/26 14:42:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN 
{
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();

		// RPN & operator = (RPN const &rhs);

		void	calculate(std::string input);

	private:
		std::stack<int>	_stack;
};