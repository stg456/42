#include "../Server.hpp"

void Server::cmdPong(std::string arg, int fd)
{
    arg = "PONG " + arg + "\r\n";
	send(fd, arg.c_str(), arg.size(), 0);
}