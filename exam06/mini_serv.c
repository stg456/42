#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


typedef struct s_client
{
    int fd;
    char str[1024];
//    int id
}           t_client;

t_client[1024];
fd_set active, readfd, writefd;
int maxfd = 0, nextid = 0;
char buftoread[120000], buftoread[120000]; 

void err(char *str) {
if (str)
    write(2, str, strlen(str));
else   
    write(2, "Fatal error", 11);
write(2, "\n", 1);
exit (1);
}

void sendAll(int senderFd)
{
    for (int fr = 0; fd <= maxfd; fd++)
        if (FD_ISSET(fd, &writefd) && fd != senderFd)
            send(fd, &buftowrite, strlen(buftowrite), 0);
}


int main(int ac, char **av)
{
    if (ac != 2)
        err("Wrong number of arguments\n");

    socklen_t ten;
    struct sockaddr_in servaddr;

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) err (NULL);
    FD_ZERO(&active);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(atoi(av[1]));
    if ((bind(socketfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) err(NULL);
    if (listen(socketfd, 10) != 0) err(NULL);
    FD_SET(socketfd, &active);
    int index = 0;
    while (1) 
    {
        readfd = writefd = active;
        if (if (select(maxfd + 1, &readfd)))
    }



        
// init const

// verif err fatal

// creer le socket

// config adresse serv

// bind du socket a l'adresse

// le socket ecoute

// init descripteur de fichier

// boucle du serveur

// glootie 

}
