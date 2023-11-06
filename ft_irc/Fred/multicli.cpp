#include <iostream>
#include <vector>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

//#include "Server.hpp"

int main()
{
	const int MAX_CLIENTS = 4096;
	//const int PORT = 6667;

	// Création d'une socket pour écouter les connexions entrantes
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		std::cerr << "[Server] Error creating socket" << std::endl;
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(PORT);

	if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		std::cerr << "[Server] Error binding socket" << std::endl;
		return 1;
	}

	if (listen(serverSocket, MAX_CLIENTS) == -1) {
		std::cerr << "[Server] Error listening on socket" << std::endl;
		return 1;
	}

	std::vector<pollfd> pollfds;
	pollfds.push_back({serverSocket, POLLIN});

	int clientcount = 0;
	while (true) {
		int activity = poll(pollfds.data(), pollfds.size(), -1); // Attend indéfiniment

		if (activity < 0) {
			std::cerr << "[Server] Error calling socket listener" << std::endl;
			break;
		}
		int test = pollfds[0].revents & POLLIN;
		if (pollfds[0].revents & POLLIN) {
			if (clientcount < MAX_CLIENTS) {
				// Nouvelle connexion entrante
				int clientSocket = accept(serverSocket, nullptr, nullptr);
				if (clientSocket == -1) {
					std::cerr << "[Server] Error accepting connection" << std::endl;
					continue;
				}
				clientcount++;
				pollfds.push_back({clientSocket, POLLIN});
				std::cout << "[Server] Incoming connection on fd " << clientSocket << std::endl;
				std::cout << "[Server] Client count: " << clientcount << std::endl;
			}
			else {
				std::cerr << "[Server] Max client count reached, connection refused " << std::endl;
				int clientSocket = accept(serverSocket, nullptr, nullptr);
				close(clientSocket);
				continue;
			}
		}

		for (size_t i = 1; i < pollfds.size(); ++i) {
			if (pollfds[i].revents & POLLIN) {
				// Lecture des données du client
				// Ajoutez ici la logique de traitement des commandes IRC
				char buffer[1024];
				ssize_t bytesRead = recv(pollfds[i].fd, buffer, sizeof(buffer), 0);
				if (bytesRead <= 0) {
					// Erreur ou déconnexion du client
					close(pollfds[i].fd);
					pollfds.erase(pollfds.begin() + i);
					clientcount--;
					i--;
				}
				else {
					// Traitement des données reçues
					std::cout << "Client " << pollfds[i].fd << " says : [" << std::string(buffer, bytesRead) << "]" << std::endl;
					//resend message from client (irssi)
					if(std::string(buffer).find("CAP LS") == 0) {
						std::cout << "[Server] 'CAP LS recu'" << std::endl;
						send(pollfds[i].fd, "CAP * LS :", bytesRead + 1, 0);
					}
					else
						send(pollfds[i].fd, buffer, bytesRead + 1, 0);

					/**********TEST****************/
					findCmd(std::string(buffer));
					/**********TEST****************/
				}
			}
		}
	}

	close(serverSocket);
	return (0);
}
