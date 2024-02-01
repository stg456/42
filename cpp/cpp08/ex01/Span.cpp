/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:37:33 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/13 15:58:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span& copy) {
	this->_size = copy._size;
}

Span::~Span() {}

Span& Span::operator = (const Span& rhs) {
	if (this != &rhs) {
		this->_size = rhs._size;
		this->_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(int nb) {
	if (_v.size() == this->_size)
		throw noAddPossibleException();
	_v.push_back(nb);
}

unsigned int Span::shortestSpan() const {
	if (_v.size() <= 1)
		throw noSpanPossibleException();
	unsigned int min;
	for (unsigned int i = 0; i < this->_size; i++) {
		for (unsigned int j = i + 1; j <= this->_size; j++) {
			if (i != j) {
				unsigned int k = std::abs(this->_v[i] - this->_v[j]);
				// std::cout << "k = " << k << std::endl;
				if (k < min)
					min = k;
			}
		}
	}
	return min;
}

unsigned int Span::longestSpan() const {
	if (_v.size() <= 1)
		throw noSpanPossibleException();
	// unsigned int max = _v[0];
	// unsigned int min = _v[0];
	// unsigned int k;
	// for (unsigned int i = 0; i < this->_size; i++) {
	// 	if (max < static_cast<unsigned int>(this->_v[i]))
	// 		max = this->_v[i];
	// 	if (min > static_cast<unsigned int>(this->_v[i]))
	// 		min = this->_v[i];
	// 	k = (max - min);
	// // std::cout << "k = " << k << std::endl;
	// }
	// return k;
	return (*std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end()));
}

const char* Span::noAddPossibleException::what() const throw() {
	return "No add possible";
}

const char* Span::noSpanPossibleException::what() const throw() {
	return "No span possible";
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	// std::iterator_traits<std::vector<int>::iterator>::difference_type diff = std::distance(begin, end);
	// srand(time(NULL));
	std::sort(begin, end);
	if (this->_v.size() + std::distance(begin, end) > this->_size)
		throw noAddPossibleException();
	this->_v.insert(this->_v.end(), begin, end);
}