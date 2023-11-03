#pragma once

#include <iostream>
#include <string>
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


class Server {
	private:
		int 			_port;
		std::string		_password;

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

class User {
	public:
		User();
		User(const User &src);
		User(int socket);
		~User();
		
		std::string	getUserNmae();
		std::string getNickName();
		std::string getSocket();
		

		void setPassword();


};
