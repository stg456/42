/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:37:33 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/10 11:55:35 by stgerard         ###   ########.fr       */
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
	this->_size = rhs._size;
	return *this;
}

void Span::addNumber(int nb) {
	if (this->_size == 0)
		throw std::exception();
	this->_size++;
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

const char* Span::noAddPossible::what() const throw() {
	return "No add possible";
}