#include "../Server.hpp"

void Server::cmdMode(std::string arg)
{//check si user qui entre la commande est un moderateur
	
	//fisrt arg <target>
   std::string target = firstArg(arg);
	//check if existe and remove
	if(arg[0] == '#') //check chan
	{
		if(findChan(target) != 1)
		{
			std::cout << " <client> <server name> " << " 403 " << target <<":No such server" << std::endl;
			return;
		}

		std::string arg2 = arg.erase(0, target.size()+1);    
		std::string mode = firstArg(arg2);
		std::cout << mode.size() << std::endl;// test size
		std::string listMode[8] = {"+i", "-i", "+t", "-t", "+k", "-k", "+l", "-l"};

	    if(mode.size() < 2)
		   std::cout << "<client> <channel> <modestring> <mode arguments>..." <<  mode.size() << std::endl;
		mode.erase(mode.size()-1, mode.size()); 
		if (mode.size() != 3 && (mode[0] != '+' || mode[0] != '-') && (mode[1] != 'i' || mode[1] != 't' || mode[1] != 'k' || mode[1] != 'l'))
		{
			std::cout <<   "501 <client> :Unknown MODE flag"<< std::endl;
			return;
		}

		int level = -1;
		for (int i = 0; i < 8; i++)
		{ 
			if (listMode[i] == mode)
			{
				level = i;
				break;
			}
		}

		switch(level)
		{
			case(0)://+i
			{
				getChan(target).setInvite(true);
				std::cout << getChan(target).getInvite() << std::endl;
				break;
			}
			case(1)://-i
			{
				getChan(target).setInvite(false);
				std::cout << getChan(target).getInvite() << std::endl;
				break;
			}
			case(2): //+t
			{
				getChan(target).setNeedProtectTopic(true);
				std::cout << getChan(target).getNeedProtectTopic() << std::endl;	
				break;
			}
			case(3): //-t
			{
				getChan(target).setNeedProtectTopic(false);
				std::cout << getChan(target).getNeedProtectTopic() << std::endl;
				break;
			}
			case(4): //+k
			{
				getChan(target).setNeedPasswordChan(true);
				std::cout << getChan(target).getNeedPasswordChan() << std::endl;
				break;
			}
			case(5): //-k
			{
				getChan(target).setNeedPasswordChan(false);
				std::cout << getChan(target).getNeedPasswordChan() << std::endl;
				break;
			}
			case(6): //+l
			{
				getChan(target).setNeedLimitUser(true);
				std::cout << getChan(target).getNeedLimitUser() << std::endl;
				break;
			}
			case(7): //-l
			{
				getChan(target).setNeedLimitUser(false);
				std::cout << getChan(target).getNeedLimitUser() << std::endl;
				break;
			}
		
			default:
			{
				std::cout << "error" << std::endl;////////////////////
				break;
			}
		}
	}
	/*else
	{
		//if(findUser(tmp != 1)//check user
		   std::cout << " 401 <client> <nickname> :No such nick/channel" << std::endl;     
		 else
		{
			????
			std::cout <<   "502 <client> :Cant change mode for other users" << std::endl;     
		}
	}
	std::cout <<"target: " << tmp << std::endl;
	std::string arg2 = arg.erase(0, tmp.size()+1);
		
	// + / - size2 ???
	std::string mode = firstArg(arg2);
	mode.erase(mode.size()-1, mode.size());
	std::cout << mode.size()<< "- mode " << mode <<std::endl;
	if (mode[0] != '+' && mode[0] != '-')
		std::cout << "error" << std::endl;
	//if (mode.size() != 2)

check i t k o l  //check flag
		std::cout << "501 <client> :Unknown MODE flag" << std::endl;

*/

}