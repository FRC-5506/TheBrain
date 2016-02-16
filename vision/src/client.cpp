#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "client.h"

int Client::send(string message) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = (struct hostent *) gethostbyname((char *) "localhost");

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5001);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    sendto(sock, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    close(sock);
}
