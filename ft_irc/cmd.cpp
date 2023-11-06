#include "Server.hpp"

void Server::findCmd(std::string request, int fd)
{
	std::string word = firstArg(request);
	
	if(request.size() == word.size())
	{
			std::cout << /*<client> <command>*/" :Not enough parameters" << std::endl; ////////////////////
			std::string test = word.erase(word.size()-1, word.size());//erase \n
	}
	else
	{
		setCmd(word);
		std::string arg = request.erase(0, word.size()+1);
	
		int level = -1;
		std::string listCmd[12]= {"NICK", "PASS", "KICK", "INVITE", "TOPIC", "MODE", "JOIN", "PRIVMSG", "NOTICE", "OPER", "QUIT", "CAP", }; // add? remove?

		for (int i = 0; i < 12; i++)
		{ 
			if (listCmd[i] == getCmd())
			{
				level = i;
				break;
			}
		}

		switch(level)
		{
			case(0):
			{
				cmdNick(arg);
				break;
			}
			case(1):
			{
				cmdPassword(arg);
				break;
			}
			case(2):
			{
				cmdKick(arg);
				break;
			}
			case(3):
			{
				cmdInvite(arg);
				break;
			}
			case(4):
			{
				cmdTopic(arg);
				break;
			}
			case(5):
			{
				cmdMode(arg);
				break;
			}
			case(6):
			{
				cmdJoin(arg, fd);
				break;
			}
			case(7):
			{
				cmdPrivmsg(arg);
				break;
			}
			case(8):
			{
				cmdNotice(arg);
				break;
			}
			case(9):
			{
				cmdOper(arg);
				break;
			}
			case(10):
			{
				cmdQuit(arg);
				break;
			}
			case(11):
			{
				cmdCap(arg);
				break;
			}
			default:
			{
				std::cout << "Error: Unknown command" << std::endl;////////////////////
				break;
			}
		}
	}
}
