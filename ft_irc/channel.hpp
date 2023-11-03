#pragma once

#include <iostream>

#include "server.hpp"
#include "user.hpp"

class User;
class Server;

class Channel
{
	private:
		std::string _name;
		// std::vector<User> _users;
		std::string _password;

	public:
		Channel();
		// channel(const channel &src);
		~Channel();

		std::string getName();
		// std::vector<User> getUsers() const;
		std::string getPassword();

		void setPassword(std::string password);


};