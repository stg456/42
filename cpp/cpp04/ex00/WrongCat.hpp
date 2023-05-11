/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:10 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/11 17:37:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		WrongCat& operator = (const WrongCat &rhs);
		~WrongCat();

	void	makeSound();
};

#endif