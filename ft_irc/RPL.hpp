#ifndef RPL_HPP
#define RPL_HPP

#define RPL_001_WELCOME     ":" + localhost + " 001 " + getUserName() + " :Welcome to the Network, " + getUserName() + "\r\n"
#define RPL_002_YOURHOST    ":" + localhost + " 002 " + getUserName() + " :Welcome to the Network, " + getUserName() + "\r\n"
#define RPL_003_CREATED     ":" + localhost + " 003 " + getUserName() + " :Welcome to the Network, " + getUserName() + "\r\n"
#define RPL_004_MYINFO	    ":" + localhost + " 004 " + getUserName() + " :Welcome to the Network, " + client.getNickName() + "\r\n"
// #define RPL_005_ISUPPORT ":" + localhost + " 005 " + getUserName() + " :Welcome to the Network, " + getUserName() + "\r\n"

#define RPL_303_TOPICWHOTIME
#define RPL_315_ENDOFWHO	

#define RPL_324_CHANNELMODE	
#define RPL_329_CREATIONTIME	
#define RPL_331_NOTOPIC	
#define RPL_332_TOPIC	
#define RPL_341_INVITING
#define RPL_352_WHOREPLY	
#define RPL_353_NAMREPLY	
#define RPL_366_ENDOFNAMES	
#define RPL_368_ENDOFBANLIST	

# define RPL_372_MOTD
# define RPL_375_MOTDSTART	
# define RPL_376_ENDOFMOTD	
# define RPL_381_YOUREOPER	

#define ERR_401_NOSUCHNICK	
#define ERR_403_NOSUCHCHANNEL	":localhost 403 " + getUserName() + " " + getChan() + " :No such channel\r\n"
#define ERR_405_TOMANYCHAN      ":localhost 405 " + getUserName() + " " + getChan() + " :Too many channel\r\n"
#define ERR_421_UNKNOWNCOMMAND
#define ERR_432_ERRONEUSNICKNAME	
#define ERR_433_NICKNAMEINUSE
#define ERR_441_USERNOTINCHANNEL	
#define ERR_442_NOTONCHANNEL	
#define ERR_443_USERONCHANNEL	
#define ERR_461_NEEDMOREPARAMS	
#define ERR_462_ALREADYREGISTERED
#define ERR_464_PASSWDMISMATCH
#define ERR_471_CHANNELISFULL
#define ERR_472_UNKNOWNCHAR	
#define ERR_473_INVITEONLYCHAN	
#define ERR_475_BADCHANNELKEY	
#define ERR_482_CHANOPRIVSNEEDED
#define ERR_519_TOOMANYUSERS
#define ERR_696_INVALIDMODEPARAM_KEY
#define ERR_696_INVALIDMODEPARAM_OP	
#define ERR_696_INVALIDMODEPARAM_UL	





#endif