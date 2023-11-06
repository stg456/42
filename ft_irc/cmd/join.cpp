#include "../Server.hpp"

void Server::cmdJoin(std::string arg, int fd)
{
	(void)fd;
	if(arg[0] != '#')
		std::cerr << " 476 " <<  arg << " :Bad Channel Mask" << std::endl;  ///////////////check error
	else
	{	
		arg.erase(0,1);
		 	arg.erase(arg.size()-1, arg.size());
		//error more than one arg ????
		if(numberOfArg(arg)!= 1) 
		/* <client> <arg>*/  std::cout << " :Not enough parameters   461" << std::endl;
		//	std::cout << " Number args"<< numberOfArg(arg) << std::endl;
		else if(arg.size() < 2) // check error if empty
			std::cout << "enter name " << std::endl;

		else
		{
			if(findChan(arg)) //if channel exist, enter
			{
				//_chanList[arg].setClientChan(???) //add Client in clientList
				_chansList[arg].getTopic();// 332
				std::cout << "welcome to chan " << arg << std::endl;
			}
			else //create channel
			{
				setChan(arg);
				//_chanList[arg].setClientChan(???)//add Client in clientList
				std::cout << getChan(arg).getNameChan() << " is create " << arg << std::endl;
		   // getChanList(); check list channels
			}
			
			//number chann max
	   /* if(getChanList().size() >= chanMax)
		  std::cout << "<client> <channel> :You have joined too many channels"  << std::endl;//405
		//client ban
			std::cout << "<client> <channel> :Cannot join channel (+b)" <<std::endl; 474

		//chann is full 471
			 std::cout << "<client> <channel> :Cannot join channel (+l)"<< std::endl;
		//invation only 473
			std::cout << "<client> <channel> :Cannot join channel (+i)" << std::endl;

		 //332 rpl topic
			  std::cout << "<client> <<channel>  ": " << getChan().getTopic() << std::endl;
		
		*/
		}
	} 
}