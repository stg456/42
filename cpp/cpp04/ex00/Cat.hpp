/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:28:55 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/21 15:35:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		// Cat(std::string type);
		Cat(const Cat &copy);
		Cat& operator = (const Cat &rhs);
		virtual ~Cat();

		virtual std::string		getType() const;
		virtual void	makeSound() const;
};

#endif