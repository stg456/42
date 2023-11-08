#ifndef CHANNEL_HPP
# define CHANNEL_HPP
# include <string>
# include <list>
# include <vector>
# include <iostream>
# include <vector>

class Channel
{
	private:
		bool					_invite;
		bool					_needPasswordChan;
		//bool					_needLimitUser;
		bool					_needProtectTopic;

		std::string				_nameChan; 
		int						_userLimit; //5 change constructor   0 = illimite
		std::string				_keyPass;
		std::string				_topic;
		std::vector<std::string> _clientChan;
		std::vector<std::string> _operatorChan;

		
		//std::list<std::string>	_chanBanList;
		
	
	public: 
		Channel();
		Channel(const Channel & src);
		~Channel();
  
		Channel& operator=(const Channel& rhs);

		//set
		void setInvite(bool invite);
		void setNeedPasswordChan(bool pass);
		//void setNeedLimitUser(bool limit);
		void setNeedProtectTopic(bool protect);

		void setKeyPass(std::string key);
		void setUserLimit(int limit);
		void setNameChan(std::string name);
		void setClientChan(std::string clientChan);
		void setTopic(std::string topic);
		//void setChanBanList(std::string name);
		void setOperatorChan(std::string oper);// a tester
	

		//get
		bool getInvite(void) const;
		bool getNeedPasswordChan(void) const;
		bool getNeedLimitUser(void) const;
		bool getNeedProtectTopic(void) const;

		std::string getKeyPass(void) const;
		int getUserLimit(void) const;
		std::string getNameChan(void) const;
		std::vector<std::string> getClientChan(void) const;
		std::string getTopic(void) const;
		//std::list<std::string> getChanListBan(void) const;
		std::vector<std::string> getOperatorChan(void) const;
		
		
		//utilsChan.cpp
		int 	clientInChan(std::string name); // 1 = ok  0 = not in chan
		void 	clearClientChan(std::string name);
		void 	getClientChanList(); //print list
		//int	 isBan(std::string nameUser); //check if user is ban return 1
		//void clearChanBanList(std::string nameUser);
		int 	isOperator(std::string oper);// 1 = is operator
		void	clearOperatorChan(std::string oper);
	
};

std::ostream& operator<<(std::ostream& flux, const Channel& chan);

#endif