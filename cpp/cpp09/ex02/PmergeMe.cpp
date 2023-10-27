/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:10 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/27 17:46:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}


PmergeMe & PmergeMe::operator = (PmergeMe const &rhs) {
	if (this != &rhs) {
		_vector = rhs._vector;
	}
	return *this;
}


bool PmergeMe::check(char *str) {
	int i = 0;

	while (str[i]) {
		if (!isdigit(str[i]))
			return true;
		i++;
	}
	return false;
}

void PmergeMe::insert(char **av) {
	int i = 1;

	while (av[i]) {
		_vector.push_back(atoi(av[i]));
		i++;
	}
}

void PmergeMe::print() {
	std::vector<int>::iterator it = _vector.begin();

	while (it != _vector.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}