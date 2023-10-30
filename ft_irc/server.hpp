#pragma once

#include <iostream>
#include <string>

class Server {
	public:
		Server();
		~Server();
		Server(const Server &src);
		Server & operator = (const Server &rhs);
};