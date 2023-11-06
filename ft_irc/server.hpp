#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>

#include "user.hpp"
#include "channel.hpp"

class User;
class Channel;

class Server {
	private:
		int 			_port;
		std::string		_password;
		int				_socket;

	public:
		Server();
		Server(const Server &src);
		Server(std::string port, std::string password);
		~Server();

		Server & operator = (const Server &rhs);

		void			set_port(std::string port);
		void			set_password(std::string password);
		void			run();


};