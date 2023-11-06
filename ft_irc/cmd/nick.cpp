#include "../Server.hpp"

void Server::cmdNick(std::string arg)
{
	//faire apparaitre dans les chan?
	/*check no space,  no :,  no# &#  #$  or use only numbers and letters
	if(arg[0] == '#' || arg[0] == '&')
		 "<client> <nick> :Erroneus nickname" 432
	already use
		 "<client> <nick> :Nickname is already in use" 433

	other
		 "<client> :No nickname given" 431
	*/

	/*std::string tmp = getNickName();  client
	setNickName(arg);
	std::cout << tmp << " changed his nickname to " << getNickName()<< std::endl;
	*/
	std::cout << arg << std::endl;
}