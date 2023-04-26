/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:57:58 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/26 13:27:20 by stgerard         ###   ########.fr       */
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
	_fix = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(int const value) {
	std::cout << "INT constructor called" << std::endl;
	_fix = value << _frac;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	float pre = 1 << _frac;
	_fix = roundf(value + pre);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fix);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fix = raw;
}

float Fixed::toFloat( void ) const 
{

}

int Fixed::toInt( void ) const 
{

}

std::ofstream &operator<<(std::ofstream &out, Fixed &arg) // a voir pour les arguments
{

}