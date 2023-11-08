#include "../Server.hpp"

void Server::cmdQuit(std::string msg, int fd)
{
	std::cout << SERVER_NAME << " cmdQuit: " << msg << std::endl;
	// - send msg to client
	sendToClient(fd, msg);
	// - close client socket
	// - remove client from _clientsMap
	// - remove client from all channels
	// - send msg to all clients in channel
	// - remove channel if empty
	// - exit
}