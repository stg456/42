#ifndef LABRADOR_HPP
# define LABRADOR_HPP

#include "Dog.hpp"

class Labrador : public Dog
{
	public:
		Labrador();
		//Labrador(std::string type);
		Labrador(const Labrador &copy);
		Labrador& operator = (const Labrador &rhs);
		virtual ~Labrador();
		
		virtual std::string		getType() const;
		virtual void	makeSound() const;
};

#endif