#include "Client.hpp"


Client::Client(){} //: _userName(""), _nickname(""), _realName("") {}
//Client::Client(std::string userName, std::string nickName, std::string realName) // fd??

Client::Client(const Client & src)
{(void)src;}

Client::~Client(){}

Client& Client::operator=(const Client& rhs) //utilisé ??
{
	if(this == &rhs)
		return(*this);
	// Affecter les valeurs membres (au cas où on l'utilise)
	return(*this);
}

std::ostream& operator<<(std::ostream& flux, const Client& rhs)
{
	flux << "User: " << rhs.getUserName() << "| Nickname: " << rhs.getNickName() << "| RealName: " << rhs.getRealName() << std::endl;
	return(flux);
}

//set
void Client::setUserName(std::string userName)
{   _userName = userName;   }
void Client::setNickName(std::string nickName)
{   _nickname = nickName;   }
void Client::setRealName(std::string realName)
{   _realName = realName;   }
void Client::setIsOperator(bool oper)
{	_isOperator = oper;	}

//get
std::string Client::getUserName(void) const
{   return(_userName);  }
std::string Client::getNickName(void) const
{   return(_nickname);  }
std::string Client::getRealName(void) const
{   return(_realName);  }
bool Client::getIsOperator(void) const
{	return(_isOperator);	}
int Client::getStatus(void) const
{	return(_status);	}

//function