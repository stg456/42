#include "Channel.hpp"

 
Channel::Channel(): _invite(false), _needPasswordChan(false), _userLimit(5){}

Channel::Channel(const Channel & src)
{(void)src;}

Channel::~Channel(){}

Channel& Channel::operator=(const Channel& rhs)
{
	if(this == &rhs)
		return(*this);
	// Affecter les valeurs membres (au cas où on l'utilise)
	return(*this);
}

std::ostream& operator<<(std::ostream& flux, const Channel& rhs)
{
	flux << rhs.getNameChan();
	return(flux);
}

//set
void Channel::setInvite(bool invite)
{   _invite = invite;   }
void Channel::setNeedPasswordChan(bool pass)
{   _needPasswordChan = pass;  }
// void Channel::setNeedLimitUser(bool limit)
// {	_needLimitUser = limit;	}
void Channel::setNeedProtectTopic(bool protect)
{	_needProtectTopic = protect;	}
void Channel::setKeyPass(std::string key)
{   _keyPass = key; }
void Channel::setUserLimit(int limit)
{   _userLimit = limit; }
void Channel::setNameChan(std::string name)
{   _nameChan = name;  }
void Channel::setClientChan(std::string client)
{   _clientChan.push_back(client);   }
void Channel::setTopic(std::string topic)
{	
	topic.erase(0,1);
	_topic = topic;
}
/*void Channel::setChanBanList(std::string name)
{	_chanBanList.push_back(name);	}*/
void Channel::setOperatorChan(std::string oper)
{	_operatorChan.push_back(oper);	}

//get
bool Channel::getInvite(void) const
{   return(_invite);    }
bool Channel::getNeedPasswordChan(void) const
{   return(_needPasswordChan);  }
//bool Channel::getNeedLimitUser(void) const
//{	return(_needLimitUser);	}
bool Channel::getNeedProtectTopic(void) const
{	return(	_needProtectTopic);	}

std::string Channel::getKeyPass(void) const
{   return(_keyPass);   }
int Channel::getUserLimit(void) const
{   return(_userLimit); }
std::string Channel::getNameChan(void) const
{   return(_nameChan);  }
std::vector<std::string> Channel::getClientChan(void) const
{   return(_clientChan);}
std::string Channel::getTopic(void) const
{   return(_topic); }
std::vector<std::string> Channel::getOperatorChan(void) const
{	return(_operatorChan);	}

