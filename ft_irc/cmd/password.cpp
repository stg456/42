#include "../Server.hpp"

void Server::cmdPassword(std::string arg)
{
	if (arg != getPassword())
	{
		std::cout <<   "<client> :Password incorrect" << std::endl; //464
		//int canEnter = 1;
	}
	else
	{
		//int canEnter = 0;
		 std::cout << arg << std::endl;
	}
}