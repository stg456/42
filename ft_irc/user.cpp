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