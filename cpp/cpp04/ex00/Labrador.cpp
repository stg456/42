#include "Labrador.hpp"

Labrador::Labrador() {
	this->type = "Labrador";
	std::cout << "Labrador default constructor called" << std::endl;
}

// Dog::Dog(std::string type) {
// 	std::cout << "Dog constructor with type called" << std::endl;
// }

Labrador::Labrador(const Labrador &copy){
	std::cout << "Labrador copy constructor called" << std::endl;
	*this = copy;
}

Labrador& Labrador::operator =(const Labrador &rhs) {
	std::cout << "Labrador assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Labrador::~Labrador() {std::cout << "Labrador destructor called" << std::endl;}

void	Labrador::makeSound() const {
	std::cout << " labrador Wouf" << std::endl;
}

std::string		Labrador::getType() const
{
	std::cout << "getType of Labrador called" << std::endl;
	return (this->type);
}