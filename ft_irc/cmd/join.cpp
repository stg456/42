#include "../Server.hpp"

void Server::cmdJoin(std::string arg, int fd)
{
	arg.erase(arg.size()-1, arg.size());
	if(arg[0] != '#')
		std::cerr << '<' << arg << "> 476" << " :Bad Channel Mask name"  << std::endl;  ///////////////check error
	else
	{	
		
		arg.erase(0,1);
		if(numberOfArg(arg)!= 1) 
			std::cerr << getUserServ(fd).getUserName() << "461 JOIN  :Not enough parameters" << std::endl;
		else
		{
			std::string tmp = firstArg(arg);
			if(tmp.size() < 1) // check error if empty
				std::cerr << '<' << tmp << "> 403 :No such channel" <<std::endl;
			else
			{
				if(findChan(tmp)) //if channel exist, enter
				{
				//getChan(tmp2).setClientChan(fd); //add Client in clientList
					// 332
					std::cout << "Welcome to chan " << tmp << std::endl;
					std::cout << "RPL_332 " << _chansList[tmp].getTopic() << std::endl;
				}
				else //create channel
				{
					setChan(tmp);
				//_chanList[arg].setClientChan()//add Client in clientList
					std::cout << getChan(tmp).getNameChan() << " is create " << std::endl;
		  		 // getChanList(); check list channels
				}
			}

//std::cout << getChanList().size()<<std::endl;
			//number chann max par clien t et max chan sever 2 erreurs differentes?
	 //  if(getChanList().size() >= getChanLimitMaxServ())
		//  std::cout <<  getChan().getNameChan() << "405 :You have joined too many channels"  << std::endl;//405
		//client ban
		// if(getChan().iaBan() == 1)
		// 	std::cout << "<client> <channel> :Cannot join channel (+b)" <<std::endl; 474

		//chann is full 471
		int tmp2 = getChan(tmp).getClientChan().size();
		std::cout << tmp2<< std::endl;
		if(getChan(tmp).getUserLimit() >= tmp2)
			 std::cout << "<client> <channel> :Cannot join channel (+l)"<< std::endl;
		// //invation only 473
		// 	std::cout << "<client> <channel> :Cannot join channel (+i)" << std::endl;

		//  //332 rpl topic
		// 	  std::cout << "<client> <<channel>  ": " << getChan().getTopic() << std::endl;
		
		
		}
	} 
}