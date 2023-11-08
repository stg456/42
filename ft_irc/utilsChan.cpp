#include "Server.hpp"
#include "Channel.hpp"
#include "Client.hpp"

int Channel::clientInChan(std::string name)
{   
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator ite = _clientChan.end();

	for(it = _clientChan.begin(); it != ite; ++it)
	{
		if(*it == name)
			return(1);
	}
	return(0);
}

void Channel::getClientChanList()
{
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator ite = _clientChan.end();

	for(it = _clientChan.begin(); it != ite; ++it)
	{
		std::cout << *it << std::endl;
	}
}

int Channel::isOperator(std::string oper)
{
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator ite = _operatorChan.end();

	for(it = _operatorChan.begin(); it != ite; ++it)
	{
		if(*it == oper)
			return(1);
	}
	return(0);
}
void Channel::clearOperatorChan(std::string oper)
{
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator ite = _operatorChan.end();

	for(it = _operatorChan.begin(); it != ite; ++it)
	{
		if(*it == oper)
			it->clear();
	}
}
/*std::list<std::string> Channel::getChanListBan(void) const
{	return(_chanBanList);	}

int Channel::isBan(std::string nameUser)
{
	std::list<std::string>::iterator it;
	std::list<std::string>::iterator ite = _chanBanList.end();

	for(it = _chanBanList.begin(); it != ite; ++it)
	{
		if(*it == nameUser)
			return(1);
	}
	return(0);
}
void Channel::clearChanBanList(std::string nameUser)
{
	std::list<std::string>::iterator it;
	std::list<std::string>::iterator ite = _chanBanList.end();

	for(it = _chanBanList.begin(); it != ite; ++it)
	{
		if(*it == nameUser)
			it->clear();
	}
}*/