/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:25:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/21 16:46:25 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria& operator = (const AMateria &rhs);
		virtual ~AMateria();

		std::string const	& getType() const;
		virtual			AMateria* clone() const = 0;
		virtual void	use(ICharacter & target);
}

#endif