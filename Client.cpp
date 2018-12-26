//
// Created by daniel on 17/12/18.
//

#include "Client.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
Client::Client(string ip, int port) {
    this->ip = ip;
    this->port = port;
}
void Client::openClient() {

    int  n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[400];


/* Create a socket point */
    GlobalNewSockfd::instance()->setSockClient(socket(AF_INET, SOCK_STREAM, 0));

    if (GlobalNewSockfd::instance()->getSockClient() < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    while (true) {
        if (connect(GlobalNewSockfd::instance()->getSockClient(), (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
            0) {
            //perror("ERROR connecting");
            //exit(1);
        }
        else {
            break;
        }
    }
/* Now ask for a message from the user, this message
   * will be read by server
*/

 /*   char buf[400];
    bzero(buffer, 400);
    printf("Please enter the message: ");
    fgets(buffer, 399, stdin);
    string str = "set controls/flight/rudder 1";
    strcpy(buf, str.c_str());
    int i = 0;
    while ( buf[i] != '\0'){
        i++;
    }
    buf[i] = '\r';
    i++;
    buf[i] = '\n';
    i++;
    buf[i] = '\0';
// Send message to the server
    n = write(GlobalNewSockfd::instance()->getSockClient(), buf, strlen(buf));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
*/


}