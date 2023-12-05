#include "user.hpp"

User::User() {}

User::User(const User &src) {
	*this = src;
}

User::User(int socket) {
	this->_socket = socket;
}

User::~User() {}

sockaddr_in server;
server.sin_addr.s_addr = inet_addr(const char* ipaddress);
server.sin_family = AF_INET;
server.sin_port = htons(int port);

If (connect(socket, &server, sizeof(server) != 0)
    // Erreur

std::string User::getUserName() const {
	return this->_userName;
}

std::string User::getNickName() const {
	return this->_nickName;
}

std::string User::getSocket() const {
	return this->_socket;
}

std::string User::getState() const {
	return this->_state;
}

void User::setPassword() {
	// this->_password = password;
}

void User::setUserName(std::string userName) {
	this->_userName = userName;
}

void User::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void User::setSocket(std::string socket) {
	this->_socket = socket;
}

void User::setMsg(std::string msg) {
	this->_msg = msg;
}

void User::setState(std::string state) {
	this->_state = state;
}
