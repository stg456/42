#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>


typedef struct s_client
{
    int id;
    char msg[1024];
}           t_client;

t_client clients[1024];
fd_set rfd, wfd, act;
int maxfd = 0, nextid = 0;
char rbuf[100000];
char wbuf[100000];

void err(char *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", 11);
    write(2, '\n', 1);
    exit (1);
}

void sendAll(int senderfd)
{
    for (int fd; fd <= maxfd; fd++)
        if (FD_ISSET(fd, &wfd) && fd != senderfd)
            send (fd, &wbuf, strlen(wbuf), 0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        err("Wrong number of arguments\n");

    socklen_t len;
    struct sockaddr_in servaddr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) err(NULL);
    FD_ZERO(&act);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

}