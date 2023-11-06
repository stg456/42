#include "Server.hpp"

int checkPort(int port) {
	if(port < 6660 || port > 7000) {
		std::cerr << "Error: port : 6660 - 7000" << std::endl;
		return(1);}
	return(0);
}

bool isNumeric(std::string const &str) {
	return (!str.empty() && str.find_first_not_of("0123456789") == std::string::npos);
}

int main(int ac, char **av) {

	Server serv;
	if(ac != 3)
	{
			std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
			return(1);
	}

	if(isNumeric(std::string(av[1])) == false)
	{
		std::cout << "Error: port : Only number" << std::endl;
		return(1);
	}
	serv.setPort(atoi(av[1]));
	if(checkPort(serv.getPort()))
		return(1);
	serv.setPassword(av[2]);

	return(serv.start());
}