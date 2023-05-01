/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:57:58 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/01 17:57:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fix(0) {
	// std::cout << "Default constructor called" << std::endl;
	// _fix = 0;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	_fix = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fix = rhs.getRawBits();
	return *this; // par this ça passe !!
}

Fixed::Fixed(int const value) {
	// std::cout << "Int constructor called" << std::endl;
	_fix = value << _frac;
}

Fixed::Fixed(float const value) {
	// std::cout << "Float constructor called" << std::endl;
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

bool Fixed::operator<(const Fixed &rhs) const {return (_fix < rhs.getRawBits());}

bool Fixed::operator>(const Fixed &rhs) const {return (_fix > rhs.getRawBits());}

bool Fixed::operator<=(const Fixed &rhs) const {return (_fix <= rhs.getRawBits());}

bool Fixed::operator>=(const Fixed &rhs) const {return (_fix >= rhs.getRawBits());}

bool Fixed::operator==(const Fixed &rhs) const {return (_fix == rhs.getRawBits());}

bool Fixed::operator!=(const Fixed &rhs) const {return (_fix != rhs.getRawBits());}

Fixed& Fixed::operator+(Fixed &rhs) const {return Fixed(toFloat() + rhs.toFloat());}

Fixed& Fixed::operator-(Fixed &rhs) const {return Fixed(toFloat() - rhs.toFloat());}

Fixed& Fixed::operator*(Fixed &rhs) const {return Fixed(toFloat() * rhs.toFloat());}

Fixed& Fixed::operator/(Fixed &rhs) const {return Fixed(toFloat() / rhs.toFloat());}

// prefix

Fixed &Fixed::operator++(void) {
	_fix++;
	return *this;
}

Fixed &Fixed::operator--(void) {
	_fix--;
	return *this;
}

//postfix

Fixed Fixed::operator++(int) {
	Fixed nb(*this);
	nb++;
	return (nb);
}

Fixed Fixed::operator--(int) {
	Fixed nb(*this);
	nb--;
	return (nb);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {return (a < b) ? a : b;}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {return (a < b) ? a : b;}

Fixed& Fixed::max(Fixed &a, Fixed &b) {return (a > b) ? a : b;}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {return (a > b) ? a : b;}
