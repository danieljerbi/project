//
// Created by daniel on 16/12/18.
//

#include "OpenServerCommand.h"
#include "DataReaderServer.h"
#include "thread"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include "iostream"
#include "GlobalNewSockfd.h"

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>


void readFrom(vector<string> input){
    DataReaderServer server = DataReaderServer(stoi(input.at(0)),stoi(input.at(1)));
    server.createServer();
}

void openServer(vector<string> input){
    int sockfd;
    int  clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(stoi(input.at(0)));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }




    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    GlobalNewSockfd::instance()->setSockServer(accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen));

    if (GlobalNewSockfd::instance()->getSockServer()  < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    char buf;
    int none = recv(GlobalNewSockfd::instance()->getSockServer(), &buf, 1, MSG_PEEK);

}

OpenServerCommand ::OpenServerCommand() {

}
void OpenServerCommand::doCommand(vector<string> strings){
    if(strings.size() != 2){
        throw "wrong amount of inputs";
    }
    char* convertTester1;
    char* convertTester2;
    strtol(strings[0].c_str(), &convertTester1, 10);
    strtol(strings[1].c_str(), &convertTester2, 10);
    if (*convertTester1 || *convertTester2) {
        throw "one or more of the arguments isn't a number";
    }
    else {
        openServer(strings);
        sleep(25);
        thread server(readFrom, strings);
        server.detach();
    }
}