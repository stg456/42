#include "Server.hpp"
//#include "Channel.hpp"

const std::string	Server::SERVER_NAME = "IRCserv.42.fr";
const int Server::MAX_CLIENTS = 1024;
const int Server::MAX_CHANS = 1024;
const int Server::MAX_CLIENTS_PER_CHAN = 50;
const int Server::MAX_CHANS_PER_CLIENT = 10;

Server::Server(){}
Server::Server(const Server & src){(void) src;}
Server::~Server(){}

Server& Server::operator=(const Server &rhs)
{
	if(this == &rhs)
		return(*this);
	// Affecter les valeurs membres (au cas où on l'utilise)
	return(*this);
}

int Server::start()
{
	setChanLimitMaxServ(MAX_CHANS);
	// Création d'une socket pour écouter les connexions entrantes
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		std::cerr << "[Server] Error creating socket" << std::endl;
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(getPort());

	if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		std::cerr << "[Server] Error binding socket" << std::endl;
		return(1);
	}

	if (listen(serverSocket, MAX_CLIENTS) == -1) {
		std::cerr << "[Server] Error listening on socket" << std::endl;
		return (1);
	}

	std::vector<pollfd> pollfds;
	pollfd pfd = {serverSocket, POLLIN, 0};
	pollfds.push_back(pfd);

	int clientcount = 0;
	while (true) {
		int activity = poll(pollfds.data(), pollfds.size(), -1); // Attend indéfiniment

		if (activity < 0) {
			std::cerr << "[Server] Error calling socket listener" << std::endl;
			break;
		}
		if (pollfds[0].revents & POLLIN) {
			if (clientcount < MAX_CLIENTS) {
				// Nouvelle connexion entrante
				int clientSocket = accept(serverSocket, NULL, NULL);
				if (clientSocket == -1) {
					std::cerr << "[Server] Error accepting connection" << std::endl;
					continue;
				}
				clientcount++;
				pollfd pfd = {clientSocket, POLLIN, 0};
				pollfds.push_back(pfd);
				std::cout << "[Server] Incoming connection on fd " << clientSocket << std::endl;
				std::cout << "[Server] Client count: " << clientcount << std::endl;
				newClient(clientSocket);
				//writeClientMap();
			}
			else {
				std::cerr << "[Server] Max client count reached, connection refused " << std::endl;
				int clientSocket = accept(serverSocket, NULL, NULL);
				close(clientSocket);
				continue;
			}
		}

		for (size_t i = 1; i < pollfds.size(); ++i) {
			if (pollfds[i].revents & POLLIN) {
				// Lecture des données du client
				char buffer[1024];
				std::memset(buffer, 0, sizeof(buffer));
				ssize_t bytesRead = recv(pollfds[i].fd, buffer, sizeof(buffer), 0);
				std::cout << "bytesRead = " << bytesRead << std::endl;
				if (bytesRead <= 0) {
					// Erreur ou déconnexion du client
					//std::cout << "Je vais eraser le client " << _clientsMap.find(pollfds[i].fd)->first << std::endl;
					_clientsMap.erase(_clientsMap.find(pollfds[i].fd));
					close(pollfds[i].fd);
					pollfds.erase(pollfds.begin() + i);
					clientcount--;
					//std::cout << "[Server] Client count: " << clientcount << std::endl;
					//writeClientMap();
					i--;
				}
				else {
					// Traitement des données reçues
					std::cout << "Client " << pollfds[i].fd << " says : [" << std::string(buffer, bytesRead) << "]" << std::endl;
					//resend message from client (irssi)
					if(std::string(buffer).find("CAP LS") == 0) {
						std::cout << "[Server] 'CAP LS recu'" << std::endl;
						sendToClient(pollfds[i].fd, "CAP * LS\n");
					}
					else
						sendToClient(pollfds[i].fd, buffer);

					/**********TEST****************/
					findCmd(std::string(buffer),pollfds[i].fd);// 
					/**********TEST****************/
				}
			}
		}
	}
	close(serverSocket);
	return (0);
}

void Server::sendToClient(int fd, std::string msg)
{
	std::cout << SERVER_NAME << " sendToClient: " << msg << std::endl;
	send(fd, msg.c_str(), msg.size(), 0);
}

/********  SET  ************* */
void Server::setNameServ(std::string name)
{	_nameServ = name;	}

void Server::setPassword(std::string password)
{	_password = password;	}

void Server::setPort(int port)
{	_port = port; }

void Server::setCmd(std::string buf)
{	
	std::transform(buf.begin(), buf.end(), buf.begin(), ::toupper);
	_cmd = buf;	
}

void Server::setChan(std::string name)
{
	_chansList[name] = Channel();
	_chansList[name].setNameChan(name);
}

void Server::newClient(int fd)
{
	Client newClient;
	_clientsMap[fd] = newClient;
	//_clientsMap[fd].setFd(fd); //répéter la clé du map ??
}

void Server::setChanLimitMaxServ(int max)
{	_chanLimitMax = max;	}

void Server::setClientMaxServ(int max)
{	_clientMaxServ = max;	}


/********  GET  ************* */
std::string Server::getNameServ(void) const
{	return(_nameServ);	}

std::string Server::getPassword(void) const
{	return(_password);	}

int Server::getPort(void) const
{	return(_port);	}

std::string Server::getCmd(void) const
{	return(_cmd);	}

std::map<std::string, Channel> Server::getChanList(void) const
{	return(_chansList);	}

int		Server::getChanLimitMaxServ(void) const
{	return(_chanLimitMax);	}

int Server::getClientMaxServ(void) const
{	return(_clientMaxServ);	}

Channel  &Server::getChan(std::string name)
{
	std::map<std::string, Channel>::iterator it;
	std::map<std::string, Channel>::iterator ite = _chansList.end();

	for(it = _chansList.begin(); it != ite; ++it)
	{
		if (it->second.getNameChan() == name)
		{
			return(it->second);
		}
	}
	return(_chansList.end()->second);///////error? //////////////////////////
}

Client  &Server::getUserServ(int fd)
{
	std::map<int,Client>::iterator it;

	it = _clientsMap.find(fd);
	if(it != _clientsMap.end())
	{
		return(it->second);
	}
	return(_clientsMap.end()->second);///////error? ////////////////
}
