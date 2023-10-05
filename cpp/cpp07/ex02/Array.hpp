/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:08:28 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/05 11:56:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <typename T>
class Array
{
	public:
	Array<T>(): _size(0) {
		_array = new T[0];
	};

	Array<T>(unsigned int n): _size(n - 1) {
		_array = new T[n];
	};

	Array<T>(Array const & src) {
		unsigned int size = src.size();
		_size = size - 1;
		_array = new T[size];

		for (unsigned int i = 0; i < size; i++)
			_array[i] = src._array[i];
	};

	~Array<T>() {
		delete [] _array;
	};

	Array<T> & operator = (Array T const & rhs) {
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