#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock() {}

Warlock::Warlock(Warlock const & src) {
	*this = src;
}

Warlock & Warlock::operator = (Warlock const & rhs) {
	this->_name = rhs._name;
	this->_titls = rhs._title;
	return *this;
}

std::string const & Warlock::getName() const {
	return (_name);
}

std::string const & Warlock::getTitle() const {
	return (_title);
}

void Warlock::setTitle(std::string const & str) {
	_title = str;
}

void introduce() const {
	std::Cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}