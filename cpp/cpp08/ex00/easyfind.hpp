/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:14:42 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/08 14:57:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <iterator>
# include <list>


template <typename T>
void easyfind(T& container, int n) {
    typename T::iterator    iter;

		iter = std::find(container.begin(), container.end(), n);
		if (iter != container.end())
			std::cout << "found " << n << std::endl;
		else
			return ("not found");
};


#endif