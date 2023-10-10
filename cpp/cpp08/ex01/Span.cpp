/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:37:33 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/10 15:00:33 by stgerard         ###   ########.fr       */
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
	// this->_size++;
	_v.push_back(nb);
}

unsigned int Span::shortestSpan() const {
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
	unsigned int max = 1;
	unsigned int l = 0;
	for (unsigned int i = 0; i < this->_size; i++) {
		for (unsigned int j = i + 1; j <= this->_size; j++) {
			if (i != j) {
				unsigned int k = std::abs(this->_v[i] - this->_v[j]);
				if (k > max)
					max = k;
			}
		}
	}
	return max;
}

const char* Span::noAddPossibleException::what() const throw() {
	return "No add possible";
}