#pragma once

#include <iostream>
#include <string>

class Server {
	private:
		int 			_port;
		std::string		_password;

	public:
		Server();
		~Server();
		Server(const Server &src);
		Server & operator = (const Server &rhs);
};