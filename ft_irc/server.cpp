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

Server::Server(std::string port, std::string password) {
	this->_port = _port;
	this->_password = _password;
}

void Server::set_port(std::string port) {
	this->_port = _port;
}

void Server::set_password(std::string password) {
	this->_password = _password;
}

void Server::run() {
	std::cout << "Server is running on port " << this->_port << std::endl;
	std::cout << "Password is " << this->_password << std::endl;






}

