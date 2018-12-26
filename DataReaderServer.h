//
// Created by daniel on 17/12/18.
//

#ifndef PROJECT_DATAREADERSERVER_H
#define PROJECT_DATAREADERSERVER_H
#include "Maps.h"


#include <sys/socket.h>

class DataReaderServer{
private:
    int port = 0;
    int rate = 0;
public:
    DataReaderServer(int server_port, int server_rate);
    void createServer();
};


#endif //PROJECT_DATAREADERSERVER_H
