#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string>			// pour les std::string
# include <cstring>			// manip sur string
# include <fcntl.h>
# include <cctype>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <vector>
# include <poll.h>
# include <list>
# include <sstream>

# include "Client.hpp"
# include "Channel.hpp"


class Server
{
	private:
		std::string						_nameServ;
		std::string						_password;
		int								_port;
		std::string 					_cmd; //delete
		std::map<int, Client>			_clientsMap;
		std::map<std::string, Channel>	_chansList;
		int 							_chanLimitMax;
	
	//add set get
		int								_clientMaxServ;
	

	public:
	 	static const std::string SERVER_NAME;
		static const int MAX_CLIENTS;
		static const int MAX_CHANS;
		static const int MAX_CLIENTS_PER_CHAN;
		static const int MAX_CHANS_PER_CLIENT;
		Server();
		Server(const Server & src);
		~Server();

		Server& operator=(const Server &rhs);

		/****** Server.cpp *******/
		int			start();
		void		sendToClient(int fd, std::string msg);

		//set
		void setNameServ(std::string);
		void setPassword(std::string _password);//directement a la creation de serv( port, password)?
		void setPort(int _port);// directement a la creation de serv( port, password)?
		void setCmd(std::string);
		void setChan(std::string name);
		void setChanLimitMaxServ(int max);
		void setClientMaxServ(int max);

		void newClient(int fd);
		//void delClient(int fd);
		//void sendToClient(int fd, std::string msg);
		//void sendToAllClient(std::string msg);

		// get
		std::string 					getNameServ(void) const;
		std::string						getPassword(void) const;
		int								getPort(void) const;
		std::string						getCmd(void) const;
		std::map<std::string, Channel>	getChanList(void) const;
		Channel							&getChan(std::string name); //one chan
		Client							&getUserServ (int fd); // one client
		int								getChanLimitMaxServ(void) const;
		int								getClientMaxServ(void) const;


		/****** utils.cpp *******/
		int			findChan(std::string arg);
		int			numberOfArg(std::string arg);
		std::string	firstArg(std::string arg);
		void		writeChanList(); //change return  list chan

		/****** utils2.cpp *******/
		void		writeClientMap();
		
		/****** cmd.cpp *******/
		void	findCmd(std::string request, int fd);


		/****** *.cpp *******/
		void	cmdJoin(std::string arg, int fd);
		void	cmdMode(std::string arg);
		void	cmdNick(std::string arg);
		void	cmdPassword(std::string arg);
		void	cmdKick(std::string arg);
		void	cmdInvite(std::string arg);
		void	cmdTopic(std::string arg);
		void	cmdPrivmsg(std::string arg);
		void	cmdNotice(std::string arg);
		void	cmdOper(std::string arg);
		void	cmdQuit(std::string arg, int fd);
		void	cmdCap(std::string arg);
};

#endif