#include "../Server.hpp"

void Server::cmdUser(std::string arg, int fd)
{
	 // 1/ username
	 // 2/ hostname
	 // 3/ servername	(optionnal)
	 // 4/ realname		(begin with ':')

	// Utilisation de stringstream pour séparer la chaîne en parties
	std::istringstream iss(arg);
	std::vector<std::string> parts;
	std::string word;
	for (int i = 0; i < 3; ++i) {
		if (!(iss >> word)) {
			std::cerr << "Erreur1 : Pas assez de paramètres dans la commande USER." << std::endl;
			sendToClient(fd, "461 USER :Wrong number of parameters");
			return;
		}
		parts.push_back(word);
	}
	// Le dernier argument peut contenir des espaces
	std::string rest;
	std::getline(iss >> std::ws, rest);
	parts.push_back(rest);

	// Vérification du nombre d'arguments
	if (parts.size() != 4) {
		std::cerr << "Erreur3 : Mauvais nombre d'arguments dans la commande USER." << parts.size() << std::endl; ////////////////
		sendToClient(fd, "461 USER :Wrong number of parameters");
		return;
	}
	// Vérification du préfixe ':'
	if (parts[3][0] != ':') {
		std::cerr << "Erreur4 : Le nom complet doit commencer par ':' " << parts[3] << std::endl; ////////////////
		sendToClient(fd, "461 USER :Wrong parameters"); // not specified in RFC
		return;
	}
	// AffectationA des variables dans le client
	_clientsMap[fd].setUserName(parts[0]);
	_clientsMap[fd].setHostName(parts[1]);
	_clientsMap[fd].setRealName(parts[3].substr(1));  // Supprimer le ':' du début du vrai nom
	std::cout << "User[" << arg << "] " << _clientsMap[fd] << std::endl; ////////////////

	// check if user is fullregistered
	//...
}