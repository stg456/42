/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:57:58 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/03 17:35:24 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fix(0) {
	std::cout << "Default constructor called" << std::endl;
	// _fix = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	_fix = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fix = rhs.getRawBits();
	return *this; // par this ça passe !!
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	_fix = value << _frac;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	float pre = 1 << _frac;
	_fix = roundf(value * pre); // * important
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fix);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_fix = raw;
}

float Fixed::toFloat(void) const {
	float f;
	f = (float)_fix / (1 << _frac);
	return (f);
}

int Fixed::toInt(void) const {
	return (_fix >> _frac);
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs) {
	out << rhs.toFloat();
	return (out);
}