#include "Server.hpp"

int Server::findChan(std::string name)
{
	/*std::list<std::string>::iterator it;
	std::list<std::string>::const_iterator ite = _fullListChan.end();

	for(it = _fullListChan.begin(); it != ite; ++it)
	{*/
	std::map<std::string, Channel>::iterator it;
	std::map<std::string, Channel>::iterator ite = _chansList.end();

	for(it = _chansList.begin(); it != ite; ++it)
	{
	
		if(it->first == name)
			return(1);
	}
	return(0);
}

int Server::numberOfArg(std::string arg)
{
	std::istringstream isstream;
	std::vector<std::string> wordList;
	std::string word;

	isstream.str(arg);
	while(getline(isstream, word, ' '))
	{
		wordList.push_back(word);
	}
	return(wordList.size());
}

std::string Server::firstArg(std::string arg)
{
	std::istringstream isstream;
	std::string word;
	isstream.str(arg);
	getline(isstream, word, ' ');
	return(word);
}

void Server::writeChanList()
{
	std::map<std::string, Channel>::iterator it = _chansList.begin();
	std::map<std::string, Channel>::iterator ite = _chansList.end();

	std::cout << "Channel list: " << std::endl;
	//for(it = _chansList.begin(); it != ite; ++it)
	for(; it != ite; ++it)
	{
		std::cout << "Chan name: " << it->first << std::endl;
	}
}