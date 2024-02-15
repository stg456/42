#include "channnel.hpp"

Channel::Channel() {}

Channel::~Channel() {}

Channel::Channel(const Channel &src) {
	*this = src;
}

std::string Channel::getName() {
	return this->_name;
}

std::string Channel::getPassword() {
	return this->_password;
}

