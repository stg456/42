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

	Server Mulhouse_42;
	Mulhouse_42.setNameServ("Mulhouse_42");
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
	Mulhouse_42.setPort(atoi(av[1]));
	if(checkPort(Mulhouse_42.getPort()))
		return(1);
	Mulhouse_42.setPassword(av[2]);

	return(Mulhouse_42.start());
}