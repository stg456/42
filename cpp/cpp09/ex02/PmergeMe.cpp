/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:10 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/30 13:59:10 by stgerard         ###   ########.fr       */
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
		_deque = rhs._deque;
	}
	return *this;
}


int PmergeMe::check(char *str) {
	int i = 0;
	while (str[i]) {
		if (isdigit(str[i])) {
			return 0;
		}
		else if (!isalpha(str[i])) {
			return 1;
		}
		i++;
	}
	return 0;
}

void PmergeMe::insert(char **av) {
	int i = 1;

	while (av[i]) {
		_vector.push_back(atoi(av[i]));
		i++;
	}

	while (av[i]) {
		_deque.push_back(atoi(av[i]));
		i++;
	}
}

void PmergeMe::print(int ac, char **av) {	
	std::cout << "Before:";
	for (int i = 1; i < ac; i++) {
		std::cout << " " << av[i];
	}
	std::cout << std::endl;

	std::clock_t start1 = std::clock();
	std::sort(_vector.begin(), _vector.end());
	std::clock_t end1 = std::clock();
	
	std::clock_t start2 = std::clock();
	std::sort(_deque.begin(), _deque.end());
	std::clock_t end2 = std::clock();
	
	std::cout << "After:";
	std::vector<int>::iterator it = _vector.begin();
	while (it != _vector.end()) {
		std::cout << " " << *it;
		it++;
	}
	std::cout << std::endl;
	
	std::cout << "Time to process with <vector>: " << std::setprecision(2) << (end1 - start1) * 1000 << std::endl;
	std::cout << "Time to process with <deque>:" << std::setprecision(2) << (end2 - start2) * 1000 << std::endl;
}