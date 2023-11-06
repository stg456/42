#include "Server.hpp"

void    Server::writeClientMap()
{
    std::map<int, Client>::const_iterator it = _clientsMap.begin();
    std::map<int, Client>::const_iterator ite = _clientsMap.end();

    std::cout << "Client list (" << _clientsMap.size() << ")" << std::endl;
    //for(it = map.begin(); it != ite; ++it)
    for(; it != ite; ++it)
    {
        std::cout << "Client : " << it->first << std::endl;
    }
}