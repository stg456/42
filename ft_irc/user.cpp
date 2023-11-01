#include "user.hpp"

User::User() {}

User::User(const User &src) {
	*this = src;
}

User::User(int socket) {
	this->_socket = socket;
}

User::~User() {}

