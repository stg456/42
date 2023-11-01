#pragma once

#include <iostream>
#include <string>

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