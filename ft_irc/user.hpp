#pragma once

#include <iostream>
#include <string>

class Sercer;

class User {
	public:
		User();
		User(const User &src);
		User(int socket);
		~User();
		
		std::string	getUserNmae();
		std::string getSocket();

		void setPassword();


};