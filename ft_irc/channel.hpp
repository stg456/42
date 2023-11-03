#pragma once

#include <iostream>

#include "server.hpp"
#include "user.hpp"

class User;
class Server;

Class Channel
{
	private:
		std::string _name;
		// std::vector<User> _users;
		std::string _password;

	public:
		channel();
		// channel(const channel &src);
		~channel();

		std::string getName();
		// std::vector<User> getUsers() const;
		std::string getPassword();

		void setPassword(std::string password);


};