#include "../Server.hpp"

void Server::cmdKick(std::string arg)
{
	if (arg.empty())
	{
		std::cout << "KICK: Not enough parameters" << std::endl;
		return;
	}
	// else if (clientInChan(std::string name) == 1)
	// {
		
	// }
	std::cout << arg << std::endl;
}