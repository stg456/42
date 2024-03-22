#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

typedef struct client
{
    int fd;
    int id
}           client;

void err(char *str)
{
    write(2, str, strlen(str));
    exit (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        err("Wrong number of arguments\n");
// init const

// verif err fatal

// creer le socket

// config adresse serv

// bind du socket a l'adresse

// le socket ecoute

// init descripteur de fichier

// boucle du serveur



}
