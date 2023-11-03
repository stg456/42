#pragma once

#include <iostream>
#include <string>

#include "server.hpp"

class Server;
class Channel;

class User {
	private:
		std::string		_userName;
		std::string		_nickName;
		std::string		_socket;
		std::string		_password;
		// Server			*_server;
		// std::string		_channel;
		std::string		_msg;
		std::string		_state;

	public:
		User();
		// User(const User &src);
		User(int socket);
		~User();
		
		std::string	getUserNmae() const;
		std::string getNickName() const;
		std::string getSocket() const;
		std::string getState() const;
		

		void setPassword();

		void setUserName(std::string userName);
		void setNickName(std::string nickName);
		void setSocket(std::string socket);
		void setMsg(std::string msg);
		void setState(std::string state);


};