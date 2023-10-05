/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:08:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/05 16:15:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>
#include <stdlib.h>

template <typename T>
class Array
{
	public:
	Array<T>(): _size(0) {
		this->_array = new T[this->_size];
	};

	Array<T>(unsigned int n): _size(n) {
		this->_array = new T[this->_size];
	};

	Array<T>(Array const & src) {
		// unsigned int size = src.size();
		// _array = new T[size];

		for (unsigned int i = 0; i < size; i++)
			this->_array[i] = src._array[i];
	};

	~Array<T>() {
		if (this->_size > 0)
			delete [] this->_array;
	};

	Array<T> & operator = (Array <T> const & rhs) {
		for (size_t i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
		return *this;
	};

	Array<T> & operator [] (unsigned int size) {
		if (size > _size)
			throw BadSizeException();
		return (this->_array[size]);
	};

	unsigned int size() const {
		return this->_size;
	};

	class BadSizeException: public std::exception {
		const char* what() const throw() {
			return "Error: the memory size is over";
	};
		// std::cout << "Error: the memory size is over" << std::endl;
	// };

	private:
		T*				_array;
		unsigned int	_size;
};

#endif