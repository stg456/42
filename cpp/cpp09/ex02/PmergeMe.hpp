/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:41:34 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 10:50:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe & operator = (PmergeMe const &rhs);

		bool check(char *str);
		void insert(char **av);
		void print(int ac);

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
};