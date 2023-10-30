#include "server.hpp"

Server::Server() {}

Server::~Server() {}

Server::Server(const Server &src) {
	*this = src;
}

Server & Server::operator = (const Server &rhs) {
	// if (this != &rhs) {
	// 	this = rhs;
	// }
	return *this;
}

