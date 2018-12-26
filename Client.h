//
// Created by daniel on 17/12/18.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include "string"
#include "GlobalNewSockfd.h"
using namespace std;
class Client {
private:
    string ip;
    int port;

public:
    Client(string, int);
    void openClient();
};


#endif //PROJECT_CLIENT_H
