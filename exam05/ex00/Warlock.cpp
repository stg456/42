#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const &src) {
	*this = src;
}

Warlock & Warlock::operator = (Warlock const & rhs) {
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job is done!" << std::endl;
}

std::string const	Warlock::getName() {
	return (_name);
}

std::string	const	getTitle() {
	return (_title);
}

void			setTitles(const std::string const & title) {

}