/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:37:33 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/10 12:25:50 by stgerard         ###   ########.fr       */
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
	if (this->_size != rhs._size)
		this->_size = rhs._size;
	return *this;
}

void Span::addNumber(int nb) {
	if (_v.size == this->_size)
		throw noAddPossibleException();
	// this->_size++;
	_v.push_back(nb);
}

unsigned int Span::shortestSpan() const {
	for (int i = 0; i < this->_size; i++) {
		for (int j = i + 1; j <= this->_size; j++) {
			if (i != j) {
				unsigned int k = std::abs(this->_size[i] - this->_size[j]);

			}
		}
	}
}

unsigned int Span::longestSpan() const {

}

const char* Span::noAddPossibleException::what() const throw() {
	return "No add possible";
}