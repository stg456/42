#ifndef CLIENT_HPP
# define CLIENT_HPP
# include <string>
# include <map>
# include <vector>
# include <list>
# include <iostream>
# include <vector>

class Client 
{
	private:
		int							_fd;
		std::string					_userName;
		std::string					_nickname;
		std::string					_realName;
		bool						_isOperator;
		int							_status;	// user, server, operator. ??..
		std::vector<std::string>	_chanCli;	//list of channels the client is on
		
	public:
		Client();
		Client(int fd);
		Client(const Client & src);
		~Client();

		Client& operator=(const Client &rhs);

		//set

		void setUserName(std::string);
		void setNickName(std::string);
		void setRealName(std::string);
		void setIsOperator(bool oper);
		void setStatus(int);

		//get
		std::string getUserName() const;
		std::string getNickName() const;
		std::string getRealName() const;
		bool 		getIsOperator() const;
		int 		getStatus() const;

};

std::ostream& operator<<(std::ostream& flux, const Client& cli);

#endif