#include "../Server.hpp"

void Server::cmdTopic(std::string arg)
{
	std::string chan = firstArg(arg);
	if(chan[0] != '#')
			std::cout << "channel not found error  arg" << std::endl; /////check error
	chan.erase(0,1);
	
	if (numberOfArg(arg) == 1)//erase '\0'
		chan.erase(chan.size()-1,chan.size());

	if(findChan(chan) != 1)
	{
		std::cout << "error chan doesn't exist "<< chan << std::endl;//////////////////
	}
	else
	{
		std::string arg2 = arg.erase(0, chan.size()+2);
		if(numberOfArg(arg2) > 0 && arg2[0] == ':')
		{
		 if(arg2.size() == 2) //clear
			getChan(chan).setTopic("");  
		 else // set topic
				getChan(chan).setTopic(arg2);
		} 
		else //see topic
			std::cout << chan << " get topic: " << getChan(chan).getTopic() << std::endl;
	}
}